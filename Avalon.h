#ifndef AVALON_H
#define AVALON_H

void print_lines();
void print_mstrs();
void select_group(int currGroup[], int csize);
void fill_rrslt(int rresult[]);
int round_result(int csize, int gp[], int bad[]);
void track_pf(int rresult[], int &pass, int &fail);
bool game_continue(int rresult[]);
bool final_result(int rresult[]);
void assign(int arr[]);
void hints(int arr[]);
void print_bad(int arr[]);
bool give_hints(int i, int rresult[]);

#endif
