BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no
NKRO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
CAPS_WORD_ENABLE = yes

# Disable this teensy 4.1 doesn't like it causes slow booting needed from QMK 22+
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=FALSE
