#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
int getsw( void ) {
    while(1) {
        return ((PORTD >> 8) & 0xf);
    }
}

int getbtns(void) {
        return ((PORTD >> 5) & 0x7);

}
int get4btns(void) {
        return ((PORTF >> 1) & 0x1);
}
