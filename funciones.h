#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


float sumarOperandos(float x,float y);
float restarOperandos(float x, float y);
float realizarDivision(float x, float y);
float realizarMultiplicacion(float primerValor, float segundoValor);
void mostrarAlerta(char mensaje[100],float primerValor, float segundoValor,int importante, char resultado[50]);
int validateIsNum(char num[], int tipo);
long factorialDeNum(int n);
float inputOperator(char operandoValidar[50], float primerOperandoActual, float segundoOperandoActual);
void allOperations(float primerValor, float segundoValor);
int esPositivo(int x);
int swapInt(int *a, int *b);

#endif // FUNCIONES_H_INCLUDED
