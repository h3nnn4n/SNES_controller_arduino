#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

#define DOWN   XK_Down
#define UP     XK_Up
#define LEFT   XK_Left
#define RIGHT  XK_Right

#define Y      XK_t
#define X      XK_r
#define A      XK_space
#define B      XK_g

#define L      XK_Shift_L
#define R      XK_q

#define START  XK_Escape
#define SELECT XK_z

int main(){
    char buffer[16];
    char old[16];

    int i;

    Display *display;
    unsigned int keycode;
    display = XOpenDisplay(NULL);

    while(1){
        strcpy(old, buffer);

        fscanf(stdin, "%s", buffer);

        //for ( i = 0 ; i < 13 ; i++ ) {
            //printf("%d = %c \t", i, buffer[i]);
        //}

        if        ( buffer[1] == '0' && old[1] == '1' ) {
            keycode = XKeysymToKeycode(display, Y);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[1] == '1' && old[1] == '0' ) {
            keycode = XKeysymToKeycode(display, Y);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[9] == '0' && old[9] == '1' ) {
            keycode = XKeysymToKeycode(display, X);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[9] == '1' && old[9] == '0' ) {
            keycode = XKeysymToKeycode(display, X);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[8] == '0' && old[8] == '1' ) {
            keycode = XKeysymToKeycode(display, A);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[8] == '1' && old[8] == '0' ) {
            keycode = XKeysymToKeycode(display, A);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[12] != '1' && old[12] == '1' ) {
            keycode = XKeysymToKeycode(display, B);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[12] == '1' && old[12] != '1' ) {
            keycode = XKeysymToKeycode(display, B);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[10] == '0' && old[10] == '1' ) {
            keycode = XKeysymToKeycode(display, L);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[10] == '1' && old[10] == '0' ) {
            keycode = XKeysymToKeycode(display, L);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[11] == '0' && old[11] == '1' ) {
            keycode = XKeysymToKeycode(display, R);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[11] == '1' && old[11] == '0' ) {
            keycode = XKeysymToKeycode(display, R);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[2] == '0' && old[2] == '1' ) {
            keycode = XKeysymToKeycode(display, SELECT);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[2] == '1' && old[2] == '0' ) {
            keycode = XKeysymToKeycode(display, SELECT);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[3] == '0' && old[3] == '1' ) {
            keycode = XKeysymToKeycode(display, START);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[3] == '1' && old[3] == '0' ) {
            keycode = XKeysymToKeycode(display, START);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[6] == '0' && old[6] == '1' ) {
            keycode = XKeysymToKeycode(display, LEFT);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[6] == '1' && old[6] == '0' ) {
            keycode = XKeysymToKeycode(display, LEFT);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[7] == '0' && old[7] == '1' ) {
            keycode = XKeysymToKeycode(display, RIGHT);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[7] == '1' && old[7] == '0' ) {
            keycode = XKeysymToKeycode(display, RIGHT);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[4] == '0' && old[4] == '1' ) {
            keycode = XKeysymToKeycode(display, UP);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[4] == '1' && old[4] == '0' ) {
            keycode = XKeysymToKeycode(display, UP);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        if        ( buffer[5] == '0' && old[5] == '1' ) {
            keycode = XKeysymToKeycode(display, DOWN);
            XTestFakeKeyEvent(display, keycode, True, 0);
        } else if ( buffer[5] == '1' && old[5] == '0' ) {
            keycode = XKeysymToKeycode(display, DOWN);
            XTestFakeKeyEvent(display, keycode, False, 0);
        }

        XFlush(display);
    }

    return EXIT_SUCCESS;
}
