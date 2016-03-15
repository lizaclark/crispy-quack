/* convert a binary full_data file to ascii format */
/* Binary output produces a full_data file with the 26
   VIC default output flux variables */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 int tmp_int, year, month, day, hour;
 float var, tmp_f;
 FILE *fpin, *fpout;
 char file_in[80], file_out[80];

int main(int argc, char **argv)
{
  if (argc<3) {
  printf("Not correct number of commandline arguments \n");
  printf("write_data_to_ascii \"binary_data_file\" \"output_ascii_data_file\" \n");
  exit(EXIT_FAILURE); }
  strcpy(file_in,argv[1]);
  printf("%s \n",file_in);
  strcpy(file_out,argv[2]);
  printf("%s \n",file_out);

 printf("opening files\n");
 if((fpin = fopen(file_in, "rb")) == NULL) {
   printf("Cannot open file %s\n", file_in);
   exit(1);
 }

 if((fpout = fopen(file_out, "w")) == NULL) {
   printf("Cannot open file %s\n", file_out);
   exit(1);
 }

 while((fread(&tmp_int,sizeof(int),1,fpin) != 0)) {
   year = (int) tmp_int;
   fread(&tmp_int,sizeof(int),1,fpin);
   month = tmp_int;
   fread(&tmp_int,sizeof(int),1,fpin);
   day = tmp_int;
   fprintf(fpout, "%d %d %d", year, month, day);
   for (var=0; var<28; var++){
     fread(&tmp_f,sizeof(float),1,fpin);
     fprintf(fpout, " %.4f", tmp_f);
   }
   fprintf(fpout,"\n");
 }
 fclose(fpin);
 fclose(fpout);
 return(0);
}
