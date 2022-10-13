#include<iostream>
#include<string.h>
#define FRAM_TXT_SIZ  3
#define MAX_NOF_FRAM  127
using namespace std;
char str[FRAM_TXT_SIZ*MAX_NOF_FRAM]; 
struct frame

{
    char text[FRAM  TXT  SIZ]; 
int seq_no;
}
fr[MAX  NOF  FRAM], shuf  ary[MAX  NOF  FRAM];
int assign_seq_no()
{ int k=0,i,j; 
for(i=0; i< tr1en(str); k++)
( fr[k].seno=k;}
for(j=0; j < FRAM  TXT  SIZ && str[i]!='\0", j++) fr[k].text[j] = str[i++];

cout<<"\nAfter assigning sequence numbers:\n"; for(i=0; i < k; i++)
cout<<i<<fr[i].text;
return k; //k gives no of frames

void generate(int *random  ary, const int limit) //generate array of random nos ( int r, i=0, j;
while(i < limit)
( r = random0 %     limit; for(j=0; j < i; j++)
if( random  ary[j] == r ) break;
if( i==j ) random  ary[i++] = r;
void shuffle( const int no_frames ) // function shuffles the frames int i, k=0, 
random_ary[no_frames];
generate(random  ary, no  frames); for(i=0; i < no  frames; i++) shuf_ary[i] = fr[random_ary[i]]; 
cout<<"\n\nAFTER SHUFFLING:\n"; for(i=0; i < no  frames; i++)
cout<<shuf  ary[i].se    no<<shuf  ary[i].text;
void sort(const int no_frames) // sorts the frames int i,j,f1ag=1;
struct frame hold;
for(i=0; i < no  frames-1 && flag-1; i++) // search for frames in sequence
