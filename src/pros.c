#include <pros.h>

void init_output() {
    __asm {
        mov ax, 0x12
        int 0x10
    }
}

void print_white(const char* s) {
    __asm {
        mov ah, 0x01
        mov si, s
        int 0x21
    }
}

void print_green(const char* s) {
    __asm {
        mov ah, 0x02
        mov si, s
        int 0x21
    }
}

void print_cyan(const char* s) {
    __asm {
        mov ah, 0x03
        mov si, s
        int 0x21
    }
}

void print_red(const char* s) {
    __asm {
        mov ah, 0x04
        mov si, s
        int 0x21
    }
}

void print_newline() {
    __asm {
        mov ah, 0x05
        int 0x21
    }
}

void clear_screen() {
    __asm {
        mov ah, 0x06
        int 0x21
    }
}

void set_color(uint8_t color) {
    __asm {
        mov ah, 0x07
        mov bl, color
        int 0x21
    }
}

void print_string(const char* s) {
    __asm {
        mov ah, 0x08
        mov si, s
        int 0x21
    }
}

void get_time(uint8_t *h, uint8_t *m, uint8_t *s) {
    __asm {
        mov ah, 0x0A
        int 0x21

        mov bx, h
        mov [bx], ch

        mov bx, m
        mov [bx], cl

        mov bx, s
        mov [bx], dh
    }
}

void get_date(uint8_t *c, uint8_t *y, uint8_t *m, uint8_t *d) {
    __asm {
        mov ah, 0x0B
        int 0x21

        mov bx, c
        mov [bx], ch
        
        mov bx, y
        mov [bx], cl
        
        mov bx, m
        mov [bx], dh
        
        mov bx, d
        mov [bx], dl
    }
}

// ===================================================

int init_fs() {
    int result;
    __asm {
        mov ah, 0x00
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int get_file_list(char* buf) {
    int result;
    __asm {
        mov ah, 0x01
        mov ax, buf
        int 0x22

        jc error
        mov result, dx
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int load_file(const char* name, uint16_t addr) {
    int result;
    __asm {
        mov ah, 0x02
        mov si, name
        mov cx, addr
        int 0x22

        jc error
        mov result, bx
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int write_file(const char* name, char* buff, uint16_t size) {
    int result;
    __asm {
        mov ah, 0x03
        mov si, name
        mov bx, buff
        mov cx, size
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int file_exists(const char* name) {
    int result;
    __asm {
        mov ah, 0x04
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int create_file(const char* name) {
    int result;
    __asm {
        mov ah, 0x05
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int remove_file(const char* name) {
    int result;
    __asm {
        mov ah, 0x06
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int rename_file(const char* old, const char* new) {
    int result;
    __asm {
        mov ah, 0x07
        mov si, old
        mov bx, new
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int get_file_size(const char* name) {
    int result;
    __asm {
        mov ah, 0x08
        mov si, name
        int 0x22

        jc error
        mov result, bx
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int change_directory(const char* name) {
    int result;
    __asm {
        mov ah, 0x09
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int go_to_parent() {
    int result;
    __asm {
        mov ah, 0x0A
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int create_directory(const char* name) {
    int result;
    __asm {
        mov ah, 0x0B
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int remove_directory(const char* name) {
    int result;
    __asm {
        mov ah, 0x0C
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

int check_directory(const char* name) {
    int result;
    __asm {
        mov ah, 0x0D
        mov si, name
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

void save_directory() {
    __asm {
        mov ah, 0x0E
        int 0x22
    }
}

void restore_directory() {
    __asm {
        mov ah, 0x0F
        int 0x22
    }
}

int load_huge_file(const char* name, uint16_t offs, uint16_t segs) {
    int result;
    __asm {
        mov ah, 0x10
        mov si, name
        mov cx, offs
        mov dx, segs
        int 0x22

        jc error
        mov result, 0
        jmp done
    error:
        mov result, -1
    done:
    }
    return result;
}

// ============================================

void draw_pixel(uint16_t x, uint16_t y, uint8_t color) {
    __asm {
        mov ax, y
        mov bx, ax
        shl ax, 6    ; y * 64
        shl bx, 4    ; y * 16
        add ax, bx   ; ax = y * 80
        
        mov bx, x
        shr bx, 3    ; x / 8
        add bx, ax   ; bx = offset

        mov cx, x
        and cx, 7
        mov ah, 0x80
        shr ah, cl

        mov dx, 0x03CE
        mov al, 0x08
        out dx, ax
        
        mov ah, color
        mov al, 0x00
        out dx, ax
        
        mov ax, 0x0F01
        out dx, ax

        mov ax, 0xA000
        mov es, ax
        
        mov al, es:[bx]
        mov es:[bx], al
    }
}

void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color) {
    uint16_t i, j;
    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            draw_pixel(x + j, y + i, color);
        }
    }
}

void draw_circle(uint16_t x0, uint16_t y0, uint16_t radius, uint8_t color) {
    uint16_t x = radius;
    uint16_t y = 0;
    uint16_t err = 0;

    while (x >= y) {
        draw_pixel(x0 + x, y0 + y, color);
        draw_pixel(x0 + y, y0 + x, color);
        draw_pixel(x0 - y, y0 + x, color);
        draw_pixel(x0 - x, y0 + y, color);
        draw_pixel(x0 - x, y0 - y, color);
        draw_pixel(x0 - y, y0 - x, color);
        draw_pixel(x0 + y, y0 - x, color);
        draw_pixel(x0 + x, y0 - y, color);

        if (err <= 0) {
            y += 1;
            err += 2 * y + 1;
        }
        if (err > 0) {
            x -= 1;
            err -= 2 * x + 1;
        }
    }
}
