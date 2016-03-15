/* convert a binary full_data file to ascii format */
/* Binary output produces a full_data file with the following variables */
        /* precipitation * 40 ,unsigned short int */
        /* air temperature * 100 ,short int  */
        /* shortwave * 50 ,unsigned short int  */
        /* longwave * 80 ,unsigned short int  */
        /* density * 100 ,unsigned short int  */
        /* pressure * 100 ,unsigned short int  */
        /* vp * 100 ,short int  */
        /* wind * 100 ,short int  */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 int x, y, z, w,f, count;
 float prcp, tmax, tmin, wind;
 FILE *fpin, *fpout;
 char file[80], file_in[80], file_out[80];
 char dummy[80],ll_list[80];
 short int          tmp_si;
 unsigned short int tmp_usi;

int main(int argc, char **argv)
{
  if (argc<3) {    
  printf("Not correct number of commandline arguments \n");
  printf("full_data_to_ascii \"full_data_file\" \"output_ascii_data_file\" \n"); 
  exit(EXIT_FAILURE); }
  strcpy(file_in,argv[1]);        printf("%s \n",file_in);
  strcpy(file_out,argv[2]);        printf("%s \n",file_out);
 
 printf("opening files\n"); 
 if((fpin = fopen(file_in, "rb")) == NULL) {
   printf("Cannot open file %s\n", file_in);
   exit(1);
 }

 if((fpout = fopen(file_out, "w")) == NULL) {
   printf("Cannot open file %s\n", file_out);
   exit(1);
 }

 while((fread(&tmp_usi,sizeof(unsigned short int),1,fpin) != 0)) {
     prcp = (float) tmp_usi/40.0;
     fread(&tmp_si,sizeof(short int),1,fpin);
     tmax = (float) tmp_si/100.0;
     fread(&tmp_si,sizeof(short int),1,fpin);
     tmin = (float) tmp_si/100.0;
     fread(&tmp_si,sizeof(short int),1,fpin);
     wind = (float) tmp_si/100.0;

   fprintf(fpout,"%.6f\t%.2f\t%.2f\t%.2f\n",
	   prcp*2,tmax,tmin,wind);
 }
 fclose(fpin);
 fclose(fpout);
 return(0);
}
