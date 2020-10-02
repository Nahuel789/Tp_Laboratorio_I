#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int utn_getNumeroFloat(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int esNumerico(char str[]);
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

int utn_getCadena(char *pAux, int len, int retry, char* mensaje, char* mensajeError);
int getCadena(char* pAux, int len);
