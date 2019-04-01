#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
 

void error(const char *s);
void cambiar(char *archivo);
 
int main(int argc, char *argv[])
{
	
    DIR *dir;
    struct dirent *ent;
    dir = opendir (".");
    if (dir == NULL)
    error("No puedo abrir el directorio");
    
    
   while ((ent = readdir (dir)) != NULL)
    {
     
      if ( (strcmp(ent->d_name, ".")!=0) && (strcmp(ent->d_name, "..")!=0) )
    {
      
      cambiar(ent->d_name);
      
      
    }
    }
  closedir (dir);
  printf("Archivos cambiados");
 
  return EXIT_SUCCESS;
}


void error(const char *s)
{
  
  perror (s);
  exit(EXIT_FAILURE);
}
void cambiar(char *archivo)
{
      int n=0;	
      char c=' ';
	  do{
	  	c=archivo[n];
	  	n++;
	  }while(c!='\0');	
	  
	  char viejo[n];
	  char nuevo[n];
	  int i;
	  for(i=0;i<n;i++){
        
	  	viejo[i]=archivo[i];
      	nuevo[i]=archivo[i];
	  }
	  nuevo[0]=toupper(nuevo[0]);
	  printf("%s %d\n",nuevo,n);
	  rename(viejo,nuevo);
	  
}
