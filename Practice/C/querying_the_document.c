#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char *kth_word_in_mth_sentence_of_nth_paragraph(char ****document, int k, int m, int n) 
{
  return document[n - 1][m - 1][k - 1];
}

char **kth_sentence_in_mth_paragraph(char ****document, int k, int m) 
{
  return document[m - 1][k - 1];
}

char ***kth_paragraph(char ****document, int k) 
{ 
    return document[k - 1]; 
}

char ****get_document(char *text) 
{
  int len = strlen(text);
  char *wrd, **sen, ***par, ****doc;
  int i, j, cnt_ch = 0, cnt_wrd = 0, cnt_sen = 0, cnt_par = 0;

  for (i = 0; i < len; i++) {
    if (text[i] == ' ') 
    {
      if (cnt_wrd == 0)
        sen = malloc(sizeof(char *));
      else
        sen = realloc(sen, (sizeof(char *) * (cnt_wrd + 1)));
      wrd[cnt_ch] = '\0';
      sen[cnt_wrd] = wrd;
      cnt_ch = 0;
      cnt_wrd++;
    } 
    else if (text[i] == '.') 
    {
      if (cnt_sen == 0)
        par = malloc(sizeof(char **));
      else
        par = realloc(par, (sizeof(char **) * (cnt_sen + 1)));
      wrd[cnt_ch] = '\0';
      sen[cnt_wrd] = wrd;
      par[cnt_sen] = sen;
      cnt_ch = 0;
      cnt_wrd = 0;
      cnt_sen++;
    } 
    else if (text[i] == '\n') 
    {
      if (cnt_par == 0)
        doc = malloc(sizeof(char ***));
      else
        doc = realloc(doc, (sizeof(char ***) * (cnt_par + 1)));
      par[cnt_sen] = sen;
      doc[cnt_par] = par;
      cnt_sen = 0;
      cnt_par++;
    } 
    else 
    {
      if (cnt_ch == 0)
        wrd = malloc(sizeof(char));
      else
        wrd = realloc(wrd, (sizeof(char) * (cnt_ch + 1)));
      wrd[cnt_ch] = text[i];
      cnt_ch++;
    }
  }
  doc = realloc(doc, (sizeof(char ***) * (cnt_par + 1)));
  doc[cnt_par] = par;
  return doc;
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

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}