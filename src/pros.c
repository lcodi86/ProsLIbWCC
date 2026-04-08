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
        shl ax, 6
        shl bx, 4
        add ax, bx
        
        mov bx, x
        shr bx, 3
        add bx, ax

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

void draw_hline(uint16_t x, uint16_t y, uint16_t w, uint8_t color) {
    if (w == 0) return;

    __asm {
        mov ax, y
        mov bx, ax
        shl ax, 6
        shl bx, 4
        add ax, bx
        mov di, x
        shr di, 3
        add di, ax

        mov ax, 0xA000
        mov es, ax

        mov dx, 0x03CE
        mov ax, 0x0205
        out dx, ax

        mov cx, w
        mov bx, x
        and bx, 7

    line_loop:
        mov al, 0x80
        push cx
        mov cl, bl
        shr al, cl
        pop cx

        mov ah, al
        mov al, 0x08
        out dx, ax

        mov al, es:[di]
        mov al, color
        mov es:[di], al

        inc bx
        cmp bx, 8
        jne skip_inc
        xor bx, bx
        inc di
    skip_inc:
        loop line_loop

        mov ax, 0x0005
        out dx, ax
    }
}

void draw_rect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint8_t color) {
    for (uint16_t i = 0; i < h; i++) {
        draw_hline(x, y + i, w, color);
    }
}

void draw_circle(int x0, int y0, int r, uint8_t color) {
    int x = -r, y = 0, err = 2 - 2 * r;
    do {
        draw_pixel(x0 - x, y0 + y, color);
        draw_pixel(x0 - y, y0 - x, color);
        draw_pixel(x0 + x, y0 - y, color);
        draw_pixel(x0 + y, y0 + x, color);
        r = err;
        if (r <= y) err += ++y * 2 + 1;
        if (r > x || err > y) err += ++x * 2 + 1;
    } while (x < 0);
}
