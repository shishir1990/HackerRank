#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};

struct document get_document(char* text) {
  int len = strlen(text);
  struct word wrd; 
  struct sentence sen; sen.word_count = 0;
  struct paragraph par; par.sentence_count = 0;
  struct document doc; doc.paragraph_count = 0;
  int i, j, cnt_ch = 0, cnt_wrd = 0, cnt_sen = 0, cnt_par = 0;

  for (i = 0; i < len; i++) {
    if (text[i] == ' ') 
    {
      if (sen.word_count == 0)
        sen.data = malloc(sizeof(struct word*));
      else
        sen.data = realloc(sen.data, (sizeof(struct word*) * (sen.word_count + 1)));
      wrd.data[cnt_ch] = '\0';
      sen.data[sen.word_count] = wrd;
      cnt_ch = 0;
      sen.word_count++;
    } 
    else if (text[i] == '.') 
    {
      if (par.sentence_count == 0)
        par.data = malloc(sizeof(char **));
      else
        par.data = realloc(par.data, (sizeof(struct sentence*) * (par.sentence_count + 1)));
      wrd.data[cnt_ch] = '\0';
      sen.data[sen.word_count] = wrd;
      par.data[par.sentence_count] = sen;
      cnt_ch = 0;
      sen.word_count = 0;
      par.sentence_count++;
    } 
    else if (text[i] == '\n') 
    {
      if (cnt_par == 0)
        doc.data = malloc(sizeof(struct paragraph*));
      else
        doc.data = realloc(doc.data, (sizeof(struct paragraph*) * (doc.paragraph_count + 1)));
      par.data[par.sentence_count] = sen;
      doc.data[doc.paragraph_count] = par;
      par.sentence_count = 0;
      doc.paragraph_count++;
    } 
    else 
    {
        if (cnt_ch == 0)


            wrd.data = malloc(sizeof(char));
        else
            wrd.data = realloc(wrd.data, (sizeof(char) * (cnt_ch + 1)));
        wrd.data[cnt_ch] = text[i];
        cnt_ch++;
    }
  }
  doc.data = realloc(doc.data, (sizeof(struct paragraph*) * (doc.paragraph_count + 1)));
  doc.data[doc.paragraph_count] = par;
  return doc;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
    return Doc.data[n - 1].data[m - 1].data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 
    return Doc.data[m - 1].data[k - 1];
}

struct paragraph kth_paragraph(struct document Doc, int k) {
    return Doc.data[k - 1];
}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
}

char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}