/*
 * main.c
 * Main code of Tree Processes: Get running processes info + some System Resource Info.
 * main.c is part of the Tree Processes.
 *
 * Written by Michael Ł. (Micha1207) in GNU Emacs.
 * 22 May 2025
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include functions
#include "func/get-ps.h"

int main(){
  /* PRINT_AND_GET_DATA */
  get_ps();
  
  return 0;
}
