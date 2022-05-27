#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#define _GNU_SOURCE
#include <inttypes.h>

int octeti(void *arr,int len);
int octeti(void *arr,int len){
	int oct = 0;
	if(arr == NULL)
		return 0;
		else
		{
			
			for(int i=0;i<len;i++){
				int lungime = *(int*)(arr + oct + 1);
				oct=oct + 5 + lungime;
			}
		}
	return oct;
}

int add_last(void **arr, int *len, data_structure *data)
{
	int lungime = octeti(*arr, *len), lungime_data = 0;
	char tip = data->header->type;
	if (tip == '1') lungime_data = 2;
	if (tip == '2') lungime_data = 6;
	if (tip == '3') lungime_data = 8;
	lungime_data += strlen((char*)data->data) + 1 + strlen((char*)(data->data + 1 + strlen((char*)data->data) + lungime_data)) + 1;
	*arr = realloc(*arr, lungime + 5 + lungime_data);
	memcpy(*arr + lungime,&data->header->type,1);
	memcpy(*arr+1 + lungime,&data->header->len,4);
	memcpy(*arr+5 + lungime,data->data,lungime_data);
	return lungime;
}

int add_at(void **arr, int *len, data_structure *data, int index)
{
	int lungime = octeti(*arr, index), lungime2 = octeti(*arr, *len);
	*arr = realloc(*arr, lungime2 + 5 + data->header->len);
	int lg_data = 5 + data->header->len;
	for (char* p = *arr + lungime2 - 1; p >= *(char**)arr + lungime; p--)
		*(p + lg_data) = *p;
	for (char* p = *arr + lungime; p < *(char**)arr + lungime + lg_data; p++)
		*p = 0;
	
	int lungime_data = 0;
	char tip = data->header->type;
	if (tip == '1') lungime_data = 2;
	if (tip == '2') lungime_data = 6;
	if (tip == '3') lungime_data = 8;
	lungime_data += strlen((char*)data->data) + 1 + strlen((char*)(data->data + 1 + strlen((char*)data->data) + lungime_data)) + 1;
	memcpy(*arr + lungime,&data->header->type,1);
	memcpy(*arr+1 + lungime,&data->header->len,4);
	memcpy(*arr+5 + lungime,data->data,lungime_data);

	return 1;
}

void find(void *arr, int len, int index) 
{
	char* p = arr;
	for(int j=0;j<len;j++)
		{
			char c = *(char*)p;
			int l = *(int*)(p + 1);
			if (c == '1')
			{
				if (j == index)
				printf("Tipul %c\n", c);
				p = p + 5;
				char* s1 = calloc(256, 1);
				char* s2 = calloc(256, 1);
				int i = 0; int lungime = 1;
				while (*(p + i) != 0) {
					s1[i] = *(p + i);
					i++;
					lungime++;
				}
				int n1 = 0, n2 = 0;
				p = p + lungime;
				memcpy(&n1, p, 1);
				memcpy(&n2, p + 1, 1);
				p += 2;
				i = 0;
				while (*(p + i) != 0) {
					s2[i] = *(p + i);
					i++;
				}
				p += i + 1;
				if (j == index)
				printf("%s pentru %s\n", s1, s2);
				if (j == index)
				printf("%hhd\n%hhd\n\n", n1, n2);
				free(s1); free(s2);
			}
			if (c == '2')
			{
				if (j == index)
				printf("Tipul %c\n", c);
				p = p + 5;
				char* s1 = calloc(256, 1);
				char* s2 = calloc(256, 1);
				int i = 0; int lungime = 1;
				while (*(p + i) != 0) {
					s1[i] = *(p + i);
					i++;
					lungime++;
				}
				int n1 = 0, n2 = 0;
				p = p + lungime;
				memcpy(&n1, p, 2);
				memcpy(&n2, p + 2, 4);
				p += 6;
				i = 0;
				while (*(p + i) != 0) {
					s2[i] = *(p + i);
					i++;
				}
				p += i + 1;
				if (j == index)
				printf("%s pentru %s\n", s1, s2);
				if (j == index)
				printf("%hd\n%d\n\n", n1, n2);
				free(s1); free(s2);
			}
			if (c == '3')
			{
				if (j == index)
				printf("Tipul %c\n", c);
				p = p + 5;
				char* s1 = calloc(256, 1);
				char* s2 = calloc(256, 1);
				int i = 0; int lungime = 1;
				while (*(p + i) != 0) {
					s1[i] = *(p + i);
					i++;
					lungime++;
				}
				int n1 = 0, n2 = 0;
				p = p + lungime;
				memcpy(&n1, p, 4);
				memcpy(&n2, p + 4, 4);
				p += 8;
				i = 0;
				while (*(p + i) != 0) {
					s2[i] = *(p + i);
					i++;
				}
				p += i + 1;
				if (j == index)
				printf("%s pentru %s\n", s1, s2);
				if (j == index)
				printf("%d\n%d\n\n", n1, n2);
				free(s1); free(s2);
			}
		
	}
}

int delete_at(void **arr, int *len, int index)
{
	int lenoct=octeti(*arr,*len);
	int lenindex=octeti(*arr,index);
	int lungimebloc = *(int*)(*arr + lenindex + 1) + 5;
	for (int i = lenindex + lungimebloc; i < lenoct; i++)
		*(char*)(*arr + i - lungimebloc) = *(char*)(*arr + i);
	*arr=realloc(*arr,lenoct-lungimebloc);
	*len -= 1;
	return 1;
}

void print(void *arr,int len){
	char* p = arr;
	for(int j=0;j<len;j++) {
		char c = *(char*)p;
		int l = *(int*)(p + 1);
		if (c == '1')
		{
			printf("Tipul %c\n", c);
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 1);
			memcpy(&n2, p + 1, 1);
			p += 2;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;

			printf("%s pentru %s\n", s1, s2);
			printf("%hhd\n%hhd\n\n", n1, n2);
			free(s1); free(s2);
		}
		if (c == '2')
		{
			printf("Tipul %c\n", c);
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 2);
			memcpy(&n2, p + 2, 4);
			p += 6;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;

			printf("%s pentru %s\n", s1, s2);
			printf("%hd\n%d\n\n", n1, n2);
			free(s1); free(s2);
		}
		if (c == '3')
		{
			printf("Tipul %c\n", c);
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 4);
			memcpy(&n2, p + 4, 4);
			p += 8;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;

			printf("%s pentru %s\n", s1, s2);
			printf("%d\n%d\n\n", n1, n2);
			free(s1); free(s2);
		}
	}

}
int castig ( void *arr, int len)
{	int max=0;
	char* p = arr;
	for(int j=0;j<len;j++) {
		char c = *(char*)p;
		int l = *(int*)(p + 1);
		if (c == '1')
		{
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 1);
			memcpy(&n2, p + 1, 1);
			p += 2;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			max=max+n1;
			max=max+n2;
			free(s1); free(s2);
		}
		if (c == '2')
		{
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 2);
			memcpy(&n2, p + 2, 4);
			p += 6;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			max=max+n1;
			max=max+n2;
			free(s1); free(s2);
		}
		if (c == '3')
		{
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 4);
			memcpy(&n2, p + 4, 4);
			p += 8;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			max=max+n1;
			max=max+n2;
			free(s1); free(s2);
		}
	}
	return max;	
}
int maxded(void *arr, int len)
{
{	int max=0;
	char* p = arr;
	for(int j=0;j<len;j++) {
		char c = *(char*)p;
		int l = *(int*)(p + 1);
		if (c == '1')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 1);
			memcpy(&n2, p + 1, 1);
			p += 2;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				max=n3;
			free(s1); free(s2);
		}
		if (c == '2')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 2);
			memcpy(&n2, p + 2, 4);
			p += 6;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				max=n3;
			free(s1); free(s2);
		}
		if (c == '3')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 4);
			memcpy(&n2, p + 4, 4);
			p += 8;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				max=n3;
			free(s1); free(s2);
		}
	}
	return max;	
}	
}
char* barosan(void *arr, int len)
{
{	int max=0;
	char *numebar=malloc(100*sizeof(char));
	char* p = arr;
	for(int j=0;j<len;j++) {
		char c = *(char*)p;
		int l = *(int*)(p + 1);
		if (c == '1')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 1);
			memcpy(&n2, p + 1, 1);
			p += 2;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				{max=n3;
				strcpy(numebar,s1);}
			free(s1); free(s2);
		}
		if (c == '2')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 2);
			memcpy(&n2, p + 2, 4);
			p += 6;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				{max=n3;
				strcpy(numebar,s1);}
			free(s1); free(s2);
		}
		if (c == '3')
		{
			int n3=0;
			p = p + 5;
			char* s1 = calloc(256, 1);
			char* s2 = calloc(256, 1);
			int i = 0; int lungime = 1;
			while (*(p + i) != 0) {
				s1[i] = *(p + i);
				i++;
				lungime++;
			}
			int n1 = 0, n2 = 0;
			p = p + lungime;
			memcpy(&n1, p, 4);
			memcpy(&n2, p + 4, 4);
			p += 8;
			i = 0;
			while (*(p + i) != 0) {
				s2[i] = *(p + i);
				i++;
			}
			p += i + 1;
			n3=n1+n2;
			if(n3 > max)
				{max=n3;
				strcpy(numebar,s1);}
			free(s1); free(s2);
		}
	}
	return numebar;
}	
}
int main() {
	// the vector of bytes u have to work with
	// good luck :)
	char cantec1[]="Dusmanii imi poarta pica , dar nu au valoarea mea ...";
	char cantec2[]="Am norocul scris in frunte e norocul meu";
	char contincan[]="Ce sa le fac la dusmani, sa le dau capul meu? ...";
	char cantec3[]="Zece mii, doua zeci de mii";
	char cont3[]="Pentru mine-s jucarii";
	char con3[]="Unde merg eu nu merg toti";
	char co3[]="Acolo-s doar mafioti";
	char c3[]="Si se intra eee Doar cu invitatie";
	char cu3[]="La costum si papion Si minim un milion ...";
	void *arr = calloc(1, 1);
	int len = 0;
	char *line = NULL;
	size_t lin = 0;
	while (getline(&line, &lin, stdin) > 0) {
		if((line[strlen(line) - 1] == '\n') || (line[strlen(line) - 1] == '\r'))
			line[strlen(line)-1] = '\0';
		char *cuv = strtok(line," ");
		if(strcmp(cuv,"insert") == 0)
			{
			data_structure *info = calloc(1,sizeof(data_structure));
			char *tip = strtok(NULL," ");
			char *nume1 = strtok(NULL," ");
			char *s1 = strtok(NULL, " ");
			char *s2 = strtok(NULL, " ");
			char *nume2 = strtok(NULL, " ");
			if(tip[0] == '1')
				{
				
				info->data = calloc(1,strlen(nume1) +1 +1 +1 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int8_t el = atoi(s1);
				int8_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,1);
				memcpy(info->data +strlen(nume1) +1 +1,&ea,1);
				memcpy(info->data +strlen(nume1) +1 +1 +1 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '1';
				info->header->len = strlen(nume1) +1+1+1+strlen(nume2)+1;
				add_last(&arr,&len,info);

				}
				else
			if(tip[0] == '2'){
				info->data = calloc(1,strlen(nume1) +1 +2 +4 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int16_t el = atoi(s1);
				int32_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,2);
				memcpy(info->data +strlen(nume1) +1 +2,&ea,4);
				memcpy(info->data +strlen(nume1) +1 +2 +4 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '2';
				info->header->len = strlen(nume1) +1+2+4+strlen(nume2)+1;
				add_last(&arr,&len,info);
				}
				else
				{
					if(tip[0] == '3')
						{
				info->data = calloc(1,strlen(nume1) +1 +4 +4 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int32_t el = atoi(s1);
				int32_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,4);
				memcpy(info->data +strlen(nume1) +1 +4,&ea,4);
				memcpy(info->data +strlen(nume1) +1 +4 +4 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '3';
				info->header->len = strlen(nume1) +1+4+4+strlen(nume2)+1;
				add_last(&arr,&len,info);
						}
				}
				len++;
				free(info->header);
				free(info->data);
				free(info);
				}
				else
				if(strcmp(cuv,"print") == 0)
					print(arr,len);
				else
				if(strcmp(cuv,"castig")==0)
				{
					printf("Suma incasata de lautar este: %d!\n",castig(arr,len));
				}
				else
				if(strcmp(cuv,"dedmax")==0)
				{
					printf("Cea mai puternica dedicatie este: %d!\n",maxded(arr,len));
				}
				else
				if(strcmp(cuv,"barosan")==0)
				{
					int dedi=maxded(arr,len);
					printf("Multumim barosanului $ %s $ pentru cea mai puternica dedicatie din seara asta, piesa aceasta este cantata in onoarea lui!\n",barosan(arr,len));
						if(dedi > 3000)
							{
								printf("*  %s\n",cantec3);
								printf("*  %s\n",cont3);
								printf("*  %s\n",con3);
								printf("*  %s\n",co3);
								printf("*  %s\n",c3);
								printf("*  %s\n",cu3);								
							}
							else
							if(dedi > 2000)
								{printf("*  %s\n",cantec2);
								printf("*  %s\n",contincan);}
							else							
							printf("*  %s\n",cantec1);
				
				}
				else
				if(strcmp(cuv,"insert_at") == 0)
					{
			char *index = strtok(NULL," ");
			int index2 = atoi(index);
			if (index2 >= len)
				index2 = len;
			char *tip = strtok(NULL," ");
			char *nume1 = strtok(NULL," ");
			char *s1 = strtok(NULL, " ");
			char *s2 = strtok(NULL, " ");
			char *nume2 = strtok(NULL, " ");
			data_structure *info = calloc(1,sizeof(data_structure));
			if(tip[0] == '1')
				{
				
				info->data = calloc(1,strlen(nume1) +1 +1 +1 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int8_t el = atoi(s1);
				int8_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,1);
				memcpy(info->data +strlen(nume1) +1 +1,&ea,1);
				memcpy(info->data +strlen(nume1) +1 +1 +1 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '1';
				info->header->len = strlen(nume1) +1+1+1+strlen(nume2)+1;
				add_at(&arr,&len,info,index2);
				}
				else
			if(tip[0] == '2'){
				info->data = calloc(1,strlen(nume1) +1 +2 +4 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int16_t el = atoi(s1);
				int32_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,2);
				memcpy(info->data +strlen(nume1) +1 +2,&ea,4);
				memcpy(info->data +strlen(nume1) +1 +2 +4 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '2';
				info->header->len = strlen(nume1) +1+2+4+strlen(nume2)+1;
				add_at(&arr,&len,info,index2);
				}
				else
				{
					if(tip[0] == '3')
						{
				info->data = calloc(1,strlen(nume1) +1 +4 +4 +strlen(nume2) +1);
				info->header = calloc(1,5);
				memcpy(info->data,nume1,strlen(nume1) + 1);
				int32_t el = atoi(s1);
				int32_t ea = atoi(s2);
				memcpy(info->data+strlen(nume1)+1,&el,4);
				memcpy(info->data +strlen(nume1) +1 +4,&ea,4);
				memcpy(info->data +strlen(nume1) +1 +4 +4 ,nume2,strlen(nume2) +1);
				//printf("%hhd\n",*(int8_t*)(info->data +strlen(nume1)+1+1));
				info->header->type = '3';
				info->header->len = strlen(nume1) +1+4+4+strlen(nume2)+1;
				add_at(&arr,&len,info,index2);
						}

				}
				free(info->header);
				free(info->data);
				free(info);
				len++;
					}
				else
				if(strcmp(cuv,"delete_at") == 0){
					char *in = strtok(NULL," ");
					int index = atoi(in);
					if (index >= len)
					index = len;
					delete_at(&arr,&len,index);
				}
				else
				if (strcmp(cuv, "find") == 0) {
					char *in = strtok(NULL," ");
					int index = atoi(in);
					if (index >= len)
					index = len;
					find(arr,len,index);
				}
				else
				if(strcmp(cuv,"exit") == 0)
					break;

	}
	free(line);
	free(arr);
	return 0;
}
