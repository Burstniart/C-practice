#include <stdio.h>
#define MAX    1000
#define MAXLINE 100
//DONE write a function that gets new llines (get the position in an array where theres \n)
//read from an array to compare the output array
// if the current line in input is the same as the current line in output skip current line in input; else read nex line in output
//if there are no more lines in output && there were no matches copy the current line in input
// proceed until there are no more lines in input

int getlines(char files[], int size, char lines[]);

int addUnique(char lines[], char result[], int position);

int main(int argc,char *argv[]) {
  char input[MAX], output[MAX], line[MAXLINE];
  char *lines = line;
  int c, i, j, position, out_position;
  char out[1000];
  i = j = 0;
  while((c = getchar()) != EOF)
      input[i++] = c;
  input[i] = '\0';
  
  //printf("%s\n", input);
  position = out_position = 0;
  /*
  do {
    position = getlines(input, position, line);
    printf("%s\n", line);
  } while (position);
  */
  char just = 'A';
  do {
    //    printf("checkpoint %c\n", just++);
    position = getlines(input, position, line);
    out_position = addUnique(line, output, out_position);
    //    printf("position in input = %d\n", position);
    //    printf("The outcome is:\n%s\n", output);
  } while (position);
  //  printf("The outcome is:\n%s\n", output);
  //  printf("~~%c~~\n",output[4]);
  printf("%s", output);
  return 0;
}

int getlines(char files[], int size, char lines[]) {

  int i, j = 0;
  i = size;
  //  printf("checkpoint 1\n");
  
  while(files[i] != '\n' && files[i] != EOF) {
    //    j++;i++;
    lines[j++] = files[i++];
  }
  //printf("checkpoint 2\n");
  if (files[i] == '\n') {
      lines[j] = '\0';
      j++;i++;    
  }
    //printf("checkpoint 3; i = %d\n", i);
  if (files[i] == '\0' || files [i] == EOF)
    return 0;
  //printf("checkpoint 4\n");
  size = i++;
  //printf("checkpoint 5\n");
  return(size);
}

int addUnique(char lines[], char result[], int position) {
  int i, j, match, end;
  j = match = end = i = 0;
  //  position = 0;
  //  i = position;
  //  printf("checkpoint 1, positon is %d\n", position);
  //  printf("find %s\nin %s\n",lines,result);
  // find match
  // LOOP IS NOT REACHING END AFTER THE 1RST ITERATION, VALIDATE VALUES
  while (!end) {
    //    printf ("last char at %d, line at %d, position is %d\n", i,j, position);
    //    printf("line:%c-output:%c\n", lines[j],result[i]);
    if (result[i] == EOF || result[i] == '\0') {
      end = 1;
      //      printf("!!doing a continue\n");
      continue;
    }
    //    printf("evaluando match, valor de i es %d\n", i);
    if ((lines[j] == result[i]) && i != 0 && (lines[j-1] == result[i-1])) {
      //            printf("!!found a match\n");
      match = 1;
    }
    //    if ()    
    //    printf("adding to counters\n");
    i++;//j++;
    if (result[i] == '\n') {
      //      printf("reseting line\n");
      j = 0;
      i++;
      //      printf("!!doing a break\n");
      //      break;//continue;
    }	else
      j++;
  }
  //    printf("checkpoint 2 may add value\n");
  //      printf("checkpoint 2 end is %d and match is %d\n", end, match);
  if( end && !match ){
    //    printf("checkpoint 3, positon in output is %d\n", position);
    //        printf("current line is: %s\n", lines);
    //    printf("checkpoint 4,i is %d and j is %d\n", i,j);
    //add line to output file
    i = position;
    j = 0;
    //    result[i++] = '\n';
    while (lines[j] != '\0') {
      result[i++] = lines[j++];    
    }
    result[i++] = '\n';
    result[i] = '\0';
    //    printf ("last char at %d, position is %d\n", i, position);
  }
  //  printf("resultado hasta ahora: %s\n", result);
  position = i;
  return position;
}
