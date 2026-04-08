[bits 16]
section _TEXT class=CODE

extern main_
global _cstart_
_cstart_:
    jmp main_
