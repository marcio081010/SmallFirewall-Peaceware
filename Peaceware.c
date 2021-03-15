#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dirent.h"
#include <time.h>
#define REGULAR_SCAN 0
#define FAST_SCAN 1

void scan(FILE* virusSign, FILE* checkFile, FILE* log, char* path, int scanType);

int main(int argc, char** argv)
{
	int i = 0;
	char action = NULL;
	char* path = NULL;
	char* logPath = NULL;
	FILE* checkFile = NULL;
	FILE* log = NULL;
	DIR& diretorio = opendir(argv[1]);
	struct dirent* files = NULL;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	   if (diretorio == NULL)
	   {
	   	printf("[!] Não foi possível abrir o diretório!");
	   	return 1;
	   }
	   FILE* virusSign = fopen(argv[2], "rb");
	   if (virusSign == NULL)
	   {
	   	printf("[!] Não foi possível abrir o vírusSign");
	   	getchar();
	   	return 1;
	   }
	printf("[#] Olá usuário, escolha a ação:\n\n\nPara varredura regular, pressione 1\npara impressão rápida pressione 2\n");
	action = getchar();
	while ((files = readdir(diretorio)))
	{
		if (strcmp(files0>d_name, ".." != 0 && strcmp(files->d_name, "." != 0)))

		{
			path = (char*)malloc(sizeof(char) * (strlen(argv[1] + files->d_namlen + 2)));

			if (path == NULL)
			{
				printf("[!] Erro de alocação de memória!");
			    return 1;
			}
			strcpy(path, argv[1]);
			path[strlen(argv[1])] = '\\';
			path[strlen(argv[1]) + 1] = '\0';
			strncat(path, files->d_name, strlen(files->d_name));
			puts(path);
			checkFile = fopen(path, "rb");
			if (checkFile == NULL)
			{
				printf("[!] ERRO!!!")
				getchar();
				return 1;
			}
		    if (action == '1')
		    {
		    	logPath = (CHAR*)malloc(sizeof(char) * strlen(argv[1] + sizeof(char) * strlen("RegularScanLog.txt") + 2));
		    	if (logPath == NULL)
		    	{
		    		printf("[!] Erro de alocação de memória");
		    		getchar();
		    		return 1;
		    	}
		    	strcpy(logPath, argv[1]);
		    	logPath[strlen(argv[1])] = '\\';
		    	logPath[strlen(argv[1]) + 1] = '\0';
		    	strncat(logPath, "RegularScanLog.txt", strlen("RegularScanLog.txt"));
		    	log = fopen(logPath, "at");
		    	if (log == NULL)
		    	{
		    		printf("[!] Não foi possível criar arquivos de log ... (sem memória, provavelmente ...)");

		    	}
		    	if (!i)
		    	{
		    		fprintf(log, "[>>] Peaceware's Antitrojan Scanneamento resultados\nScan date: %d-%d-%d %d:%d:%d\nFolder to scan : %s \nVirus signature : %s \nScanning option : Regular Scan \nResults :\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, argv[1], argv[2]);
		    		i = 1;
		    	}
		    	scan(virusSign, checkFile, log, path, REGULAR_SCAN);

		    	if (action == '2')

		    		logPath = (char*)malloc(sizeof(char) * strlen(argv[1]) + sizeof(char) * strlen("FastScanLog.txt") + 2);
		    	    if (logPath == NULL)
		    	    {
		    	       printf("[!] Erro de alocação de memória");
		    	       getchar();
		    	       return 1;
		    	    }
		    	    strcpy(logPath, argv[1]);
		    	    logPath[strlen(argv[1])] = '\\';
		    	    logPath[strlen(argv[1]) + 1] = '\0';
		    	    strncat(logPath, "FastScanLog.txt", strlen("FastScanLog.txt"));
		    	    log = fopen(logPath, "at");
		    	    if (log == NULL)
		    	    {
		    	    	printf("[!] Não foi possível criar arquivos de log ... (sem memória, provavelmente ...)");
		    	    }
		    	    if (!i)
		    	    {
		    	    	fprintf("[>>] peaceware's Antitrojan Scanneamento resultados\nScan date: %d-%d-%d %d:%d:%d\nFolder to scan : %s \nVirus signature : %s \nScanning option : Regular Scan \nResults :\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, argv[1], argv[2]);
		    	    	i = 1;
		    	    }

		    	    scan(virusSign, checkFile, log, path, FastScanLog);
		    }
		}
	}   

	free(logPath);
	free(path);
	fclose(log);
	fclose(checkFile);
	getchar();
	getchar();	
	return 0;
}

void scan(FILE* virusSign, FILE* checkFile, FILE* log, char* path , int scanType)
{
    int virusLen = 0, i = 0, j = 0, seekStart = 0, flag = 0, found = 0,checkFilelength = 0;
	fseek(virusSign, 0, SEEK_END);
	virusLen = ftell(virusSign);
	fseek(virusSign, 0, SEEK_SET);
	fseek(checkFile, 0, SEEK_END);
	checkFilelength = ftell(checkFile);
	fseek(checkFile, 0, SEEK_SET);
	if (scanType == REGULAR_SCAN)
}
          while (checkFile != EOF && found == 0)
          {
          	      for (i = 0; i < virusLen && flag == 0; i++)
          	      {
          	      	    if (seekStart + i > checkFilelength)
          	      	    {
          	      	    	found = -1;
          	      	    }
          	      	    if (fgetc(virusSign) != fgetc(checkFile))
          	      	    {
          	      	    	flag = 1;
          	      	    }	
          	      }	
          	      if (flag == 0)
          	      {
          	      	fprint(log, "[>>] O Arquivo %s\n esta infectado!!", path)
          	        printf("[!] O arquivo está infectado\n")
          	        found = 1;	
          	      }
          	      else
          	      {
          	      	flag = 0;
          	      	seekStart++;
          	      	fseek(virusSign, 0, SEEK_SET);
          	      	fseek(checkFile, seekStart, SEEK_SET);
          	      }

          }
          if (found != 1)
          {
          	fprintf(log, "[#] O arquivo %s está limpo de Virus!!!\n\n", path);
          	printf("[#] Arquivo está limpo.\n");
          }
          else if (scanType == FAST_SCAN)
          {
          	checkFilelength /= 5;
          	for (seekStart = 0; seekStart < checkFilelength && found == 0; seekStart++)
          	{
          		for (i = 0; i < virusLen && flag == 0; i++)
          		{
          			if (seekStart + i > checkFilelength)
          			{
          				found = -1;
          			}
          			if (fgetc(virusSign) != fgetc(checkFile))
          			{
          				flag = 1;
          			}
          		}
          		if (flag == 0)
          		{
          			fprintf(log, "[>>] O arquivo %s está infectado!!! -- (encontrado nos 20 primeiros %c de arquivo)\n\n", path, '%');
          			printf("[!] O arquivo está infectado\n")
          			found = 1;
          		}
          		else
          		{
          			flag = 0;
          			seekStart++;
          			fseek(virusSign, 0, SEEK_SET);
          			fseek(checkFile, seekStart, SEEK_SET);
          		}
          	}
          	if (found != 1)
          	{
          		fseek(checkFile, (checkFilelength * 4), SEEK_SET);
          		checkFilelength *= 5;
          		while (checkFile != EOF && found == 0)
          		{
          			for (i = 0; i < virusLen && flag == 0; i++)
          			{
          				if (seekStart + i > checkFilelength)
          				{
          					found = -1;
          				}
          				if (fgetc(virusSign) != fgetc(checkFile))
          				{
          					flag = 1;
          				}
          			}
          			if (flag == 0)
          			{
          				fprintf("[>>] O arquivo %s está infectado!!! -- (encontrado nos 20 primeiros %c de arquivo)\n\n", path, '%');
          				printf("[!] O arquivo está infectado");
          				found = 1;
          			}
          			else
          			{
          				flag = 0;
          				seekStart++;
          				fseek(virusSign, 0, SEEK_SET);
          				fseek(checkFile, seekStart, SEEK_SET);
          			}
          		}
          		if (found != 1)
          		{
          			 fprintf(log, "[#] O arquivo %s está limpo de Virus!!!\n\n", path);
          	         printf("[#] Arquivo está limpo.\n");
          		}
          	}
          }
