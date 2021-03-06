#pragma once


#include <string>



/***************************************************************
 *
 *                   CONSTANTS & ENUM
 */

typedef FILE* ct_file;


#define FALSE                       0
#define TRUE                       1


/* Memory allocation */
#define CT_MALLOC(_n)             malloc(_n)
#define CT_REALLOC(_p,_n)         realloc(_p,_n)
#define CT_FREE(_p)               free(_p)
#define CT_NEW(_t)                (_t*)CT_MALLOC(sizeof(_t))


/* File access */
#define CT_FOPEN_S(_fp,_f,_m)     fopen_s(_fp,_f,_m)
#define CT_FCLOSE(_f)             fclose(_f)
#define CT_FREAD(_p,_s,_n,_f)     fread(_p,_s,_n,_f)
#define CT_FWRITE(_p,_s,_n,_f)    fwrite(_p,_s,_n,_f)
#define CT_FSEEK(_f,_n,_set)      fseek(_f,_n,_set)
#define CT_FTELL(_f)              ftell(_f)

/* Memory functions */
#define CT_MEMCPY(_dst,_src,_n)   memcpy(_dst,_src,_n)
#define CT_MEMSET(_s,_c,_n)       memset(_s,_c,_n)

/* String functions */
#define CT_STRLEN(_s)             strlen(_s)
#define CT_STRCMP(_s,_t)          strcmp(_s,_t)
#define CT_STRNCMP(_s,_t,_n)      strncmp(_s,_t,_n)
#define CT_STRCPY_S(_dst,_size,_src)    strcpy_s(_dst,_size,_src)



#define CT_FPRINTF                fprintf
#define CT_VSNPRINTF          vsnprintf



#define CT_OK        (0)
#define CT_FAILED    (-1)

#define ct_return_if_fail(cond) \
if(cond) \
    ; \
else \
    return

#define ct_return_val_if_fail(cond, val) \
 ct_return_if_fail(cond) (val)



/**
 * log levels.
 */
enum ct_log_level
{
    CT_PANIC,   /**< The synth can't function correctly any more */
    CT_ERR,     /**< Serious error occurred */
    CT_WARN,    /**< Warning */
    CT_INFO,    /**< Verbose informational messages */
    CT_DBG,     /**< Debugging messages */
    CT_LAST_LOG_LEVEL,
};

int ct_log(int level, const char* fmt, ...);
#define CT_LOG                    ct_log






#define MAX_NUMBER_OF_TRACKS 128
#define MAX_NUMBER_OF_CHANNELS 16
#define MIDI_FILE_HEADER_SIZE  14

enum ct_midi_event_type
{
    /* channel messages */
    NOTE_OFF = 0x80,
    NOTE_ON = 0x90,
    KEY_PRESSURE = 0xa0,
    CONTROL_CHANGE = 0xb0,
    PROGRAM_CHANGE = 0xc0,
    CHANNEL_PRESSURE = 0xd0,
    PITCH_BEND = 0xe0,
    /* system exclusive */
    MIDI_SYSEX = 0xf0,
    /* meta event - for midi files only */
    MIDI_META_EVENT = 0xff
};


enum midi_meta_event
{
    MIDI_TEXT = 0x01,
    MIDI_COPYRIGHT = 0x02,
    MIDI_TRACK_NAME = 0x03,
    MIDI_INST_NAME = 0x04,
    MIDI_LYRIC = 0x05,
    MIDI_MARKER = 0x06,
    MIDI_CUE_POINT = 0x07,
    MIDI_EOT = 0x2f,
    MIDI_SET_TEMPO = 0x51,
    MIDI_SMPTE_OFFSET = 0x54,
    MIDI_TIME_SIGNATURE = 0x58,
    MIDI_KEY_SIGNATURE = 0x59,
    MIDI_SEQUENCER_EVENT = 0x7f
};



/***************************************************************
 *
 *         TYPE DEFINITIONS & FUNCTION DECLARATIONS
 */


 /*
  * ct_midi_event_t
  */
struct ct_midi_event_t
{
    ct_midi_event_t* next; /* Link to next event */
    void* paramptr;           /* Pointer parameter (for SYSEX data), size is stored to param1, param2 indicates if pointer should be freed (dynamic if TRUE) */
    unsigned int dtime;       /* Delay (ticks) between this and previous event. midi tracks. */
    unsigned int param1;      /* First parameter */
    unsigned int param2;      /* Second parameter */
    unsigned char type;       /* MIDI event type */
    unsigned char channel;    /* MIDI channel */
};


/*
 * ct_track_t
 */
struct ct_track_t
{
    char* name;
    int num;
    ct_midi_event_t* first;
    ct_midi_event_t* last;
    char bp_ChannelUsed[MAX_NUMBER_OF_CHANNELS];
    int i_TrackStartPos;
    int i_TrackLenght;
    int i_EventStartPosInTrack;
};


/*
 * ct_midi_file
 */
typedef struct
{
    char* buffer;           /* Entire contents of MIDI file (borrowed) */
    int buf_len;                  /* Length of buffer, in bytes */
    int buf_pos;                  /* Current read position in contents buffer */
    int eof;                      /* The "end of file" condition */
    int type;
    int ntracks;
    unsigned int division;       /* division is ticks per beat (quarter-note) */
    int tracklen;

    ct_track_t* clpp_Track[MAX_NUMBER_OF_TRACKS];
    char bp_ChannelUsed[MAX_NUMBER_OF_CHANNELS];
    char cp_HeaderBuffer[MIDI_FILE_HEADER_SIZE];

} ct_midi_file;


/*
 * ct_midi_eventbuffer
 */
typedef struct
{
    char* buffer;           /* Entire contents of MIDI file (borrowed) */
    int buf_len;                  /* Length of buffer, in bytes */
    int buf_pos;                  /* Current read position in contents buffer */
    int eof;                      /* The "end of file" condition */
    int running_status;
    int c;
    int eot;
    int varlen;
    int dtime;
} ct_midi_trackevent_buf;






