#include "DataSave.h"
#include "stdafx.h"
#include <stdio.h>
#include "stdlib.h"
bool DataSave(FILE*File_z,float *pAltitude,int row,int col)
{
	float *word_z = (float *)calloc( (size_t) (col*row), sizeof(float ));
	for (int j=0;j<row;j++)
	{	
		for(int i=0;i<col;i++)
		{
			word_z[j*col+i] = (*(pAltitude+j*col+i));
		}
	}

	/*for(int i=0;i<40;i++)
		printf("%f\n",word_z[i]);*/
	/*fwrite(&col,sizeof(int),1,File_z);
	fwrite(&row,sizeof(int),1,File_z);*/
	fwrite(word_z,sizeof(float),row*col,File_z);
	/*fclose(File_z);*/
	return true;
}