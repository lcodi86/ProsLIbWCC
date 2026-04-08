#ifndef PROS_H
#define PROS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned char  uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long  uint32_t;

// Output API (0x21)
void init_output();
void print_white(const char* s);
void print_green(const char* s);
void print_cyan(const char* s);
void print_red(const char* s);

void print_newline();
void clear_screen();

void set_color(uint8_t color); // uint8_t color (valid values: 0x00–0x0F, corresponding to VGA 16-color palette)
void print_string(const char* s);

// h - hours, m - minutes, s - seconds
void get_time(uint8_t *h, uint8_t *m, uint8_t *s);

// c - century, y - year, m - month, d - day
void get_date(uint8_t *c, uint8_t *y, uint8_t *m, uint8_t *d);

// FS API (0x22) Functions can return errors or a result, -1 is an error
int init_fs();

int get_file_list(char* buf);
int get_file_size(const char* name);

int write_file(const char* name, char* buff, uint16_t size); // size in bytes
int file_exists(const char* name);
int create_file(const char* name); // create empty file
int remove_file(const char* name);
int rename_file(const char* old, const char* new);

int change_directory(const char* name);
int go_to_parent();
int create_directory(const char* name);
int remove_directory(const char* name);
int check_directory(const char* name);
void save_directory();
void restore_directory();

int load_file(const char* name, uint16_t addr);
int load_huge_file(const char* name, uint16_t offs, uint16_t segs);

// ==================
void draw_pixel(uint16_t x, uint16_t y, uint8_t color);
void draw_hline(uint16_t x, uint16_t y, uint16_t w, uint8_t color);
void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color);
void draw_circle(int x0, int y0, int r, uint8_t color);

#ifdef __cplusplus
}
#endif

#endif /* PROS_H */
