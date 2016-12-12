#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

/**
 *  Bibliotecas Trabajo Práctico III - Laboratorio I
 *  Alumno: Juan Marcos Vallejo - 1ro G. 01/11/2016
 *
 */

int validateIsAge(char num[]);
int validateIsName(char name[]);
int validateIsTel(char num[]);
int validateIsPos(int x);
int validateIsNum(char num[], int tipo);
int validateIsNotZero(int x);
int validateField(char* buffer, int tamanioArreglo, int typeOfValidate, int lengthFrom, int lengthTo);

#endif // VALIDACIONES_H
