#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdio.h>
#include "keycodes.h"

#define N_LAYERS    4
#define N_ROWS      5
#define N_COLS      6

#define NO_KEY      KC_NTH


uint8_t keymap[2][N_LAYERS][N_ROWS][N_COLS] = {
    /* LEFT SIDE */
    {
        /*  BASE LAYER */
        {
            { KB_GRAC , KB_1    , KB_2    , KB_3    , KB_4     , KB_5    },
            { KB_TAB  , KB_Q    , KB_W    , KB_E    , KB_R     , KB_T    },
            { KB_ESCP , KB_A    , KB_S    , KB_D    , KB_F     , KB_G    },
            { KB_LSHF , KB_Z    , KB_X    , KB_C    , KB_V     , KB_B    },
            { KB_LCTL , KB_LALT , KB_LGUI , KC_LFK1 , KB_MINS  , KB_SPCB }
        },

        /*  FN1 LAYER */
        {
            { KC_LEDU , KB_F1   , KB_F2   , KB_F3   , KB_F4   , KB_F5   },
            { KC_LEDD , KB_F6   , KB_F7   , KB_F8   , KB_F9   , KB_F10  },
            { KB_CLCK , KB_F11  , KB_F12  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , KB_VOUP , KB_VODW , KB_MUTE , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , KB_RGUI , KC_LFK1 , NO_KEY  , NO_KEY  }
        },

        /*  FN2 LAYER */
        {
            { NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  }
        }
    },

    /*  RIGHT SIDE */
    {
        /*  BASE LAYER */
        {
            { KB_6    , KB_7    , KB_8    , KB_9    , KB_0    , KB_BCKS },
            { KB_Y    , KB_U    , KB_I    , KB_O    , KB_P    , KB_BSLH },
            { KB_H    , KB_J    , KB_K    , KB_L    , KB_SCLN , KB_APOS },
            { KB_N    , KB_M    , KB_CMMA , KB_PERD , KB_SLSH , KB_RSHF },
            { KB_ENTR , KB_EQUL , KC_LFK1 , KC_LFK2 , KB_RALT , KB_RCTL }
        }, 

        /*  FN1 LAYER */
        {
            { KB_PRSC , KB_SLCK , KB_PAUS , KB_INSR , NO_KEY  , NO_KEY  },
            { KB_HOME , KB_END  , KB_PGDW , KB_PGUP , NO_KEY  , NO_KEY  },
            { KB_LARR , KB_DARR , KB_UARR , KB_RARR , NO_KEY  , NO_KEY  },
            { KB_LBRC , KB_RBRC , NO_KEY  , NO_KEY  , NO_KEY  , NO_KEY  },
            { NO_KEY  , NO_KEY  , KC_LFK1 , NO_KEY  , KB_MENU , NO_KEY  }
        },

        /*  FN2 LAYER */
        {
            { NO_KEY  , KP_7    , KP_8    , KP_9    , KP_MINS , NO_KEY  },
            { NO_KEY  , KP_4    , KP_5    , KP_6    , KP_PLUS , NO_KEY  },
            { NO_KEY  , KP_1    , KP_2    , KP_3    , KP_ASTX , NO_KEY  },
            { NO_KEY  , NO_KEY  , KP_0    , KP_PERD , KP_SLSH  , NO_KEY  },
            { KP_ENTR , NO_KEY  , NO_KEY  , KC_LFK2 , NO_KEY  , NO_KEY  }
        }

    }
}




#endif