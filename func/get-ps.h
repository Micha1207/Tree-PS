#ifndef GET_PS_H
#define GET_PS_H

#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>
#include "get-ps.h"

int is_pid(const char *name) {
  for (int i = 0; name[i]; i++){
    if (!isdigit(name[i])){
      return 0;
    }
    
    return 1;
  }
}

int get_ps(void) {
  DIR *proc = opendir("/proc");
  if (!proc) {
    printf("Brak /proc.\n");
    return 1;
  }
  
  struct dirent *entry;
  printf("PID   CMD\n");
  while ((entry = readdir(proc)) != NULL) {
    if (!is_pid(entry->d_name))
            continue;
    
    char path[256];
    snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
    FILE *f = fopen(path, "r");
    if (f) {
      char cmd[256];
      if (fgets(cmd, sizeof(cmd), f)) {
	cmd[strcspn(cmd, "\n")] = 0;
	printf("%5s  %s\n", entry->d_name, cmd);
      }
      fclose(f);
    }
  }
  
  closedir(proc);
  return 0;
}

#endif
