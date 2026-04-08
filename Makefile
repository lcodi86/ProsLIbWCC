AS = nasm
CC = wcc
LD = wlink

CFLAGS = -i=include -1 -za99 -ot -ms -bt=dos -s -zl -zq
BUILD_DIR = build
IMG = test/x16pros.img
BIN_NAME = program.bin
MAIN = $(BUILD_DIR)/$(BIN_NAME)

OBJS = $(BUILD_DIR)/start.obj $(BUILD_DIR)/main.obj $(BUILD_DIR)/pros.obj

all: $(MAIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/pros.obj: src/pros.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -fo=$@ $<

$(BUILD_DIR)/main.obj: test/main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -fo=$@ $<

$(BUILD_DIR)/start.obj: test/start.asm | $(BUILD_DIR)
	$(AS) -f obj $< -o $@

$(MAIN): $(OBJS)
	$(LD) disable 1014 name $@ \
		format raw bin \
		$(foreach f,$(OBJS),file $(f)) \
		option quiet, eliminate, start=_cstart_ \
		option objalign=16 \
		option offset=0x8000

run: $(MAIN)
	mcopy -i $(IMG) -o $(MAIN) ::$(BIN_NAME)
	@echo "Done! File $(BIN_NAME) is in $(IMG)"
	qemu-system-i386 -fda $(IMG)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
