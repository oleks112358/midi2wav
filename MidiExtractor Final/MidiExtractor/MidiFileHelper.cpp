#include <iostream>
#include <string>
#include "MidiFileHelper.h"
#include<vector>
#include<memory>


//------------------------------------------------------------------------------------
//
CMidiFileHelper::CMidiFileHelper()
{
	clp_MidiFile = NULL;
}



//------------------------------------------------------------------------------------
//
CMidiFileHelper::~CMidiFileHelper()
{
	delete_ct_midi_file(&clp_MidiFile);
}




//------------------------------------------------------------------------------------
//
std::string CMidiFileHelper::fnGetInstrumentName(int iaProgID)
{
	switch (iaProgID + 1) {
	case 1: {
		return "Acoustic Grand Piano";
	}
	case 2: {
		return "Bright Acoustic Piano";
	}
	case 3: {
		return "Electric Grand Piano";
	}
	case 4: {
		return "Honky-tonk Piano";
	}
	case 5: {
		return " Electric Piano 1";
	}
	case 6: {
		return "Electric Piano 2";
	}
	case 7: {
		return "Harpsichord";
	}
	case 8: {
		return "Clavinet (Clavi)";
	}
	case 9: {
		return "Celesta";
	}
	case 10: {
		return "Glockenspiel";
	}
	case 11: {
		return "Music Box";
	}
	case 12: {
		return "Vibraphone";
	}
	case 13: {
		return "Marimba";
	}
	case 14: {
		return "Xylophone";
	}
	case 15: {
		return "Tubular Bells";
	}
	case 16: {
		return "Dulcimer";
	}
	case 17: {
		return "Drawbar Organ";
	}
	case 18: {
		return "Percussive Organ";
	}
	case 19: {
		return "Rock Organ";
	}
	case 20: {
		return "Church Organ";
	}
	case 21: {
		return "Reed Organ";
	}
	case 22: {
		return "Accordion";
	}
	case 23: {
		return "Harmonica";
	}
	case 24: {
		return "Tango Accordion";
	}
	case 25: {
		return "Acoustic Guitar (nylon)";
	}
	case 26: {
		return "Acoustic Guitar (steel)";
	}
	case 27: {
		return "Electric Guitar (jazz)";
	}
	case 28: {
		return "Electric Guitar (clean)";
	}
	case 29: {
		return "Electric Guitar (muted)";
	}
	case 30: {
		return "Overdriven Guitar";
	}
	case 31: {
		return "Distortion Guitar";
	}
	case 32: {
		return "Guitar harmonics";
	}
	case 33: {
		return "Acoustic Bass";
	}
	case 34: {
		return "Electric Bass (finger)";
	}
	case 35: {
		return "Electric Bass (pick)";
	}
	case 36: {
		return "Fretless Bass";
	}
	case 37: {
		return "Slap Bass 1";
	}
	case 38: {
		return "Slap Bass 2";
	}
	case 39: {
		return "Synth Bass 1";
	}
	case 40: {
		return "Synth Bass 2";
	}
	case 41: {
		return "Violin";
	}
	case 42: {
		return "Viola";
	}
	case 43: {
		return "Cello";
	}
	case 44: {
		return "Contrabass";
	}
	case 45: {
		return "Tremolo Strings";
	}
	case 46: {
		return "Pizzicato Strings";
	}
	case 47: {
		return "Orchestral Harp";
	}
	case 48: {
		return "Timpani";
	}
	case 49: {
		return "String Ensemble 1";
	}
	case 50: {
		return "String Ensemble 2";
	}
	case 51: {
		return "Synth Strings 1";
	}
	case 52: {
		return "Synth Strings 2";
	}
	case 53: {
		return "Choir Aahs";
	}
	case 54: {
		return "Voice Oohs";
	}
	case 55: {
		return "Synth Choir";
	}
	case 56: {
		return "Orchestra Hit";
	}
	case 57: {
		return "Trumpet";
	}
	case 58: {
		return "Trombone";
	}
	case 59: {
		return "Tuba";
	}
	case 60: {
		return "Muted Trumpet";
	}
	case 61: {
		return "French Horn";
	}
	case 62: {
		return "Brass Section";
	}
	case 63: {
		return "Synth Brass 1";
	}
	case 64: {
		return "Synth Brass 2";
	}
	case 65: {
		return "Soprano Sax";
	}
	case 66: {
		return "Alto Sax";
	}
	case 67: {
		return "Tenor Sax";
	}
	case 68: {
		return "Baritone Sax";
	}
	case 69: {
		return "Oboe";
	}
	case 70: {
		return "English Horn";
	}
	case 71: {
		return "Bassoon";
	}
	case 72: {
		return "Clarinet";
	}
	case 73: {
		return "Piccolo";
	}
	case 74: {
		return "Flute";
	}
	case 75: {
		return "Recorder";
	}
	case 76: {
		return "Pan Flute";
	}
	case 77: {
		return "Blown Bottle";
	}
	case 78: {
		return "Shakuhachi";
	}
	case 79: {
		return "Whistle";
	}
	case 80: {
		return "Ocarina";
	}
	case 81: {
		return "Lead 1 (square)";
	}
	case 82: {
		return "Lead 2 (sawtooth)";
	}
	case 83: {
		return "Lead 3 (calliope)";
	}
	case 84: {
		return "Lead 4 (chiff)";
	}
	case 85: {
		return "Lead 5 (charang)";
	}
	case 86: {
		return "Lead 6 (voice)";
	}
	case 87: {
		return "Lead 7 (fifths)";
	}
	case 88: {
		return "Lead 8 (bass + lead)";
	}
	case 89: {
		return "Pad 1 (new age)";
	}
	case 90: {
		return "Pad 2 (warm)";
	}
	case 91: {
		return "Pad 3 (polysynth)";
	}
	case 92: {
		return "Pad 4 (choir)";
	}
	case 93: {
		return "Pad 5 (bowed)";
	}
	case 94: {
		return "Pad 6 (metallic)";
	}
	case 95: {
		return "Pad 7 (halo)";
	}
	case 96: {
		return "Pad 8 (sweep)";
	}
	case 97: {
		return "FX 1 (rain)";
	}
	case 98: {
		return "FX 2 (soundtrack)";
	}
	case 99: {
		return "FX 3 (crystal)";
	}
	case 100: {
		return "FX 4 (atmosphere)";
	}
	case 101: {
		return "FX 5 (brightness)";
	}
	case 102: {
		return "FX 6 (goblins)";
	}
	case 103: {
		return "FX 7 (echoes)";
	}
	case 104: {
		return "FX 8 (sci-fi)";
	}
	case 105: {
		return "Sitar";
	}
	case 106: {
		return "Banjo";
	}
	case 107: {
		return "Shamisen";
	}
	case 108: {
		return "Koto";
	}
	case 109: {
		return "Kalimba";
	}
	case 110: {
		return "Bag pipe";
	}
	case 111: {
		return "Fiddle";
	}
	case 112: {
		return "Shanai";
	}
	case 113: {
		return "Tinkle Bell";
	}
	case 114: {
		return "Agogo";
	}
	case 115: {
		return "Steel Drums";
	}
	case 116: {
		return "Woodblock";
	}
	case 117: {
		return "Taiko Drum";
	}
	case 118: {
		return "Melodic Tom";
	}
	case 119: {
		return "Synth Drum";
	}
	case 120: {
		return "Reverse Cymbal";
	}
	case 121: {
		return "Guitar Fret Noise";
	}
	case 122: {
		return "Breath Noise";
	}
	case 123: {
		return "Seashore";
	}
	case 124: {
		return "Bird Tweet";
	}
	case 125: {
		return "Telephone Ring";
	}
	case 126: {
		return "Helicopter";
	}
	case 127: {
		return "Applause";
	}
	case 128: {
		return "Gunshot";
	}
	}
	return "out of range";
}





//------------------------------------------------------------------------------------
/**
* Check if a file is a MIDI file.
* @param filename Path to the file to check
* @return TRUE if it could be a MIDI file, FALSE otherwise
*
* The current implementation only checks for the "MThd" header in the file.
* It is useful only to distinguish between SoundFont and MIDI files.
*/
int CMidiFileHelper::ct_is_midifile(std::string claSFileName)
{
	FILE* fp = NULL;
	char id[4];
	int retcode = FALSE;

	do
	{
		if ((0 != CT_FOPEN_S(&fp, claSFileName.c_str(), "rb")) || !fp)
		{
			CT_LOG(CT_ERR, "Unable to open file");
			return retcode;
		}

		if (CT_FREAD(&id, sizeof(id), 1, fp) != 1)
		{
			break;
		}

		if (id[0] == 'M' && id[1] == 'T' && id[2] == 'h' && id[3] == 'd')
			retcode = TRUE;
	} while (0);

	CT_FCLOSE(fp);

	return retcode;
}



/**
* Return a new MIDI file handle for parsing an already-loaded MIDI file.
* @internal
* @param buffer Pointer to full contents of MIDI file (borrows the pointer).
*  The caller must not free buffer until after the ct_midi_file is deleted.
* @param length Size of the buffer in bytes.
* @return New MIDI file handle or NULL on error.
*/
ct_midi_file* CMidiFileHelper::new_ct_midi_file(char* buffer, size_t length)
{
	ct_midi_file* mf;

	mf = CT_NEW(ct_midi_file);
	if (mf == NULL)
	{
		CT_LOG(CT_ERR, "Low on memory");
		return NULL;
	}

	CT_MEMSET(mf, 0, sizeof(ct_midi_file));

	mf->buffer = buffer;
	mf->buf_len = length;
	mf->buf_pos = 0;
	mf->eof = FALSE;

	if (ct_midi_file_read_mthd(mf) != CT_OK)
	{
		CT_FREE(mf);
		return NULL;
	}

	return mf;
}




char* CMidiFileHelper::ct_file_read_full(ct_file fp, size_t* length)
{
	size_t buflen;
	char* buffer;
	size_t n;

	/* Work out the length of the file in advance */
	if (CT_FSEEK(fp, 0, SEEK_END) != 0)
	{
		CT_LOG(CT_ERR, "File load: Could not seek within file");
		return NULL;
	}

	buflen = ftell(fp);

	if (CT_FSEEK(fp, 0, SEEK_SET) != 0)
	{
		CT_LOG(CT_ERR, "File load: Could not seek within file");
		return NULL;
	}

	buffer = (char*)CT_MALLOC(buflen);

	if (buffer == NULL)
	{
		CT_LOG(CT_PANIC, "Out of memory");
		return NULL;
	}

	n = CT_FREAD(buffer, 1, buflen, fp);

	if (n != buflen)
	{
		CT_LOG(CT_ERR, "Only read %lu bytes; expected %lu", (unsigned long)n,
			(unsigned long)buflen);
		CT_FREE(buffer);
		return NULL;
	};

	*length = n;

	return buffer;
}

/**
* Delete a MIDI file handle.
* @internal
* @param mf MIDI file handle to close and free.
*/
void CMidiFileHelper::delete_ct_midi_file(ct_midi_file** pmf)
{
	ct_return_if_fail(pmf != NULL);
	auto mf = *pmf;
	ct_return_if_fail(mf != NULL);

	if (mf->buffer)
		CT_FREE(mf->buffer);

	for (int i = 0; i < MAX_NUMBER_OF_TRACKS; i++)
		delete_ct_track(&mf->clpp_Track[i]);

	CT_FREE(mf);
	*pmf = NULL;
}









ct_midi_trackevent_buf* CMidiFileHelper::new_ct_midi_trackevent_buf(char* buffer, size_t length)
{
	ct_midi_trackevent_buf* mf;

	mf = CT_NEW(ct_midi_trackevent_buf);
	if (mf == NULL)
	{
		CT_LOG(CT_ERR, "Low on memory");
		return NULL;
	}

	CT_MEMSET(mf, 0, sizeof(ct_midi_trackevent_buf));

	mf->c = -1;
	mf->running_status = -1;

	mf->buffer = buffer;
	mf->buf_len = length;
	mf->buf_pos = 0;
	mf->eof = FALSE;

	return mf;
}



/**
* Delete a MIDI file handle.
* @internal
* @param mf MIDI file handle to close and free.
*/
void CMidiFileHelper::delete_ct_midi_trackevent_buf(ct_midi_trackevent_buf** pmf)
{
	ct_return_if_fail(pmf != NULL);
	auto mf = *pmf;
	ct_return_if_fail(mf != NULL);

	CT_FREE(mf);
	*pmf = NULL;
}











/*
 * ct_midi_file_skip
 */
int CMidiFileHelper::ct_midi_file_skip(ct_midi_file* mf, int skip)
{
	int new_pos = mf->buf_pos + skip;

	/* Mimic the behaviour of fseek: Error to seek past the start of file, but
	 * OK to seek past end (this just puts it into the EOF state). */
	if (new_pos < 0)
	{
		CT_LOG(CT_ERR, "Failed to seek position in file");
		return CT_FAILED;
	}

	/* Clear the EOF flag, even if moved past the end of the file (this is
	 * consistent with the behaviour of fseek). */
	mf->eof = FALSE;
	mf->buf_pos = new_pos;
	return CT_OK;
}

/*
 * ct_midi_file_eof
 */
int CMidiFileHelper::ct_midi_file_eof(ct_midi_file* mf)
{
	/* Note: This does not simply test whether the file read pointer is past
	 * the end of the file. It mimics the behaviour of feof by actually
	 * testing the stateful EOF condition, which is set to TRUE if getc or
	 * fread have attempted to read past the end (but not if they have
	 * precisely reached the end), but reset to FALSE upon a successful seek.
	 */
	return mf->eof;
}



/*
 * ct_isasciistring
 */
int CMidiFileHelper::ct_isasciistring(char* s)
{
	/* From ctype.h */
#define ct_isascii(c)    (((c) & ~0x7f) == 0)

	size_t i, len = CT_STRLEN(s);

	for (i = 0; i < len; i++)
	{
		if (!ct_isascii(s[i]))
		{
			return 0;
		}
	}

	return 1;

#undef ct_isascii
}




/*
 * ct_getlength
 */
long CMidiFileHelper::ct_getlength(unsigned char* s)
{
	long i = 0;
	i = s[3] | (s[2] << 8) | (s[1] << 16) | (s[0] << 24);
	return i;
}




/*
 * ct_midi_file_read_mthd
 */
int CMidiFileHelper::ct_midi_file_read_mthd(ct_midi_file* mf)
{
	auto mthd = mf->cp_HeaderBuffer;

	if (ct_midi_file_read(mf, mthd, MIDI_FILE_HEADER_SIZE) != CT_OK)
	{
		return CT_FAILED;
	}

	if ((CT_STRNCMP(mthd, "MThd", 4) != 0) || (mthd[7] != 6) || (mthd[9] > 2))
	{
		CT_LOG(CT_ERR,
			"Doesn't look like a MIDI file: invalid MThd header");
		return CT_FAILED;
	}

	mf->type = mthd[9];
	mf->ntracks = (unsigned)mthd[11];
	mf->ntracks += (unsigned int)(mthd[10]) << 16;

	if ((signed char)mthd[12] < 0)
	{
		CT_LOG(CT_ERR, "File uses SMPTE timing -- Not implemented yet");
		return CT_FAILED;
	}
	else
	{
		mf->division = ((unsigned)mthd[12] << 8) | ((unsigned)mthd[13] & 0xff);
	}

	return CT_OK;
}


/*
 * ct_midi_file_read
 */
int CMidiFileHelper::ct_midi_file_read(ct_midi_file* mf, void* buf, int len)
{
	int num = len < mf->buf_len - mf->buf_pos
		? len : mf->buf_len - mf->buf_pos;

	if (num != len)
	{
		mf->eof = TRUE;
	}

	if (num < 0)
	{
		num = 0;
	}

	/* Note: Read bytes, even if there aren't enough, but only increment
	 * trackpos if successful (emulates old behaviour of ct_midi_file_read)
	 */
	CT_MEMCPY(buf, mf->buffer + mf->buf_pos, num);
	mf->buf_pos += num;

	return (num != len) ? CT_FAILED : CT_OK;
}


/*
 * ct_midi_file_read
 */
int CMidiFileHelper::ct_midi_file_read(ct_midi_trackevent_buf* tb, void* buf, int len)
{
	int num = len < tb->buf_len - tb->buf_pos
		? len : tb->buf_len - tb->buf_pos;

	if (num != len)
	{
		tb->eof = TRUE;
	}

	if (num < 0)
	{
		num = 0;
	}

	/* Note: Read bytes, even if there aren't enough, but only increment
	 * trackpos if successful (emulates old behaviour of ct_midi_file_read)
	 */
	CT_MEMCPY(buf, tb->buffer + tb->buf_pos, num);
	tb->buf_pos += num;

	return (num != len) ? CT_FAILED : CT_OK;
}



/*
 * ct_midi_file_add_track
 */
int CMidiFileHelper::ct_midi_file_add_track(ct_midi_file* mf, ct_track_t* track)
{
	// Find the first empty track.
	for (int i = 0; i < MAX_NUMBER_OF_TRACKS; i++)
	{
		if (NULL == mf->clpp_Track[i])
		{
			mf->clpp_Track[i] = track;

			// Now lets add this tracks channel to our master file.
			for (int iJ = 0; iJ < MAX_NUMBER_OF_CHANNELS; iJ++)
			{
				if (0 != track->bp_ChannelUsed[iJ])
					mf->bp_ChannelUsed[iJ] = true;
			}

			return CT_OK;
		}
	}

	return CT_FAILED;
}




/**
 * Create a MIDI event structure.
 * @return New MIDI event structure or NULL when out of memory.
 */
ct_midi_event_t* CMidiFileHelper::new_ct_midi_event()
{
	ct_midi_event_t* evt;
	evt = CT_NEW(ct_midi_event_t);

	if (evt == NULL)
	{
		CT_LOG(CT_ERR, "Out of memory");
		return NULL;
	}
	CT_MEMSET(evt, 0, sizeof(ct_midi_event_t));

	evt->dtime = 0;
	evt->type = 0;
	evt->channel = 0;
	evt->param1 = 0;
	evt->param2 = 0;
	evt->next = NULL;
	evt->paramptr = NULL;
	return evt;
}


/**
 * Delete MIDI event structure.
 * @param evt MIDI event structure
 */
void CMidiFileHelper::delete_ct_midi_event(ct_midi_event_t** pevt)
{
	ct_return_if_fail(pevt != NULL);

	auto evt = *pevt;
	ct_return_if_fail(evt != NULL);

	ct_midi_event_t* temp;
	while (evt)
	{
		temp = evt->next;

		/* Dynamic SYSEX event? - free (param2 indicates if dynamic) */
		if ((evt->type == MIDI_SYSEX || (evt->type == MIDI_TEXT) || (evt->type == MIDI_LYRIC)) &&
			evt->paramptr && evt->param2)
		{
			CT_FREE(evt->paramptr);
		}

		CT_FREE(evt);
		evt = temp;
	}

	*pevt = NULL;
}




/*
 * new_ct_track
 */
ct_track_t* CMidiFileHelper::new_ct_track(int num)
{
	ct_track_t* track;
	track = CT_NEW(ct_track_t);

	if (track == NULL)
	{
		return NULL;
	}
	CT_MEMSET(track, 0, sizeof(ct_track_t));

	track->name = NULL;
	track->num = num;
	track->first = NULL;
	track->last = NULL;
	return track;
}

/*
 * delete_ct_track
 */
void CMidiFileHelper::delete_ct_track(ct_track_t** ptrack)
{
	ct_return_if_fail(ptrack != NULL);
	auto track = *ptrack;
	ct_return_if_fail(track != NULL);

	if (track->name)
		CT_FREE(track->name);
	delete_ct_midi_event(&track->first);
	CT_FREE(track);

	*ptrack = NULL;
}


/*
 * ct_track_set_name
 */
int CMidiFileHelper::ct_track_set_name(ct_track_t* track, char* name)
{
	size_t len;

	if (track->name != NULL)
	{
		CT_FREE(track->name);
	}

	if (name == NULL)
	{
		track->name = NULL;
		return CT_OK;
	}

	len = CT_STRLEN(name);
	track->name = (char*)CT_MALLOC(len + 1);

	if (track->name == NULL)
	{
		CT_LOG(CT_ERR, "Out of memory");
		return CT_FAILED;
	}

	CT_STRCPY_S(track->name, (len + 1), name);
	return CT_OK;
}




/*
 * ct_track_add_event
 */
int CMidiFileHelper::ct_track_add_event(ct_track_t* track, ct_midi_event_t* evt)
{
	evt->next = NULL;

	if (track->first == NULL)
	{
		track->first = evt;
		track->last = evt;
	}
	else
	{
		track->last->next = evt;
		track->last = evt;
	}

	if (NOTE_ON == evt->type && evt->param2 > 0 )
	{
		track->bp_ChannelUsed[evt->channel] = true;
	}


	return CT_OK;
}






/*
 * ct_midi_file_read_event
 */
int CMidiFileHelper::ct_midi_file_read_event(ct_midi_trackevent_buf* tb, ct_track_t* track, bool* bpaSupportedChannels, int iaDesiredBPM)
{
	int status;
	int type;
	int tempo;
	unsigned char* metadata = NULL;
	unsigned char* dyn_buf = NULL;
	unsigned char static_buf[256];
	int nominator, denominator, clocks, notes;
	ct_midi_event_t* evt;
	int channel = 0;
	int param1 = 0;
	int param2 = 0;
	int size;

	/* read the delta-time of the event */
	if (ct_midi_file_read_varlen(tb) != CT_OK)
	{
		return CT_FAILED;
	}

	tb->dtime += tb->varlen;

	/* read the status byte */
	status = ct_midi_file_getc(tb);

	if (status < 0)
	{
		CT_LOG(CT_ERR, "Unexpected end of file");
		return CT_FAILED;
	}

	/* not a valid status byte: use the running status instead */
	if ((status & 0x80) == 0)
	{
		if ((tb->running_status & 0x80) == 0)
		{
			CT_LOG(CT_ERR, "Undefined status and invalid running status");
			return CT_FAILED;
		}

		ct_midi_file_push(tb, status);
		status = tb->running_status;
	}

	/* check what message we have */

	tb->running_status = status;

	if (status == MIDI_SYSEX)    /* system exclusif */
	{
		/* read the length of the message */
		if (ct_midi_file_read_varlen(tb) != CT_OK)
		{
			return CT_FAILED;
		}

		if (tb->varlen)
		{
			metadata = (unsigned char*)CT_MALLOC(tb->varlen + 1);

			if (metadata == NULL)
			{
				CT_LOG(CT_PANIC, "Out of memory");
				return CT_FAILED;
			}

			/* read the data of the message */
			if (ct_midi_file_read(tb, metadata, tb->varlen) != CT_OK)
			{
				CT_FREE(metadata);
				return CT_FAILED;
			}

			evt = new_ct_midi_event();

			if (evt == NULL)
			{
				CT_LOG(CT_ERR, "Out of memory");
				CT_FREE(metadata);
				return CT_FAILED;
			}

			evt->dtime = tb->dtime;
			size = tb->varlen;

			if (metadata[tb->varlen - 1] == 0xf7)
			{
				size--;
			}

			/* Add SYSEX event and indicate that its dynamically allocated and should be freed with event */
			ct_midi_event_set_sysex_LOCAL(evt, MIDI_SYSEX, metadata, size, TRUE);
			ct_track_add_event(track, evt);
			tb->dtime = 0;
		}

		return CT_OK;

	}
	else if (status == MIDI_META_EVENT)      /* meta events */
	{

		int result = CT_OK;

		/* get the type of the meta message */
		type = ct_midi_file_getc(tb);

		if (type < 0)
		{
			CT_LOG(CT_ERR, "Unexpected end of file");
			return CT_FAILED;
		}

		/* get the length of the data part */
		if (ct_midi_file_read_varlen(tb) != CT_OK)
		{
			return CT_FAILED;
		}

		if (tb->varlen < 255)
		{
			metadata = &static_buf[0];
		}
		else
		{
			dyn_buf = (unsigned char*)CT_MALLOC(tb->varlen + 1);

			if (dyn_buf == NULL)
			{
				CT_LOG(CT_PANIC, "Out of memory");
				return CT_FAILED;
			}

			metadata = dyn_buf;
		}

		/* read the data */
		if (tb->varlen)
		{
			if (ct_midi_file_read(tb, metadata, tb->varlen) != CT_OK)
			{
				if (dyn_buf)
				{
					CT_FREE(dyn_buf);
				}

				return CT_FAILED;
			}
		}

		/* handle meta data */
		switch (type)
		{

		case MIDI_COPYRIGHT:
			metadata[tb->varlen] = 0;
			break;

		case MIDI_TRACK_NAME:
			metadata[tb->varlen] = 0;
			ct_track_set_name(track, (char*)metadata);
			break;

		case MIDI_INST_NAME:
			metadata[tb->varlen] = 0;
			break;

		case MIDI_LYRIC:
		case MIDI_TEXT:
		{
			void* tmp;
			int size = tb->varlen + 1;

			/* NULL terminate strings for safety */
			metadata[size - 1] = '\0';

			evt = new_ct_midi_event();

			if (evt == NULL)
			{
				CT_LOG(CT_ERR, "Out of memory");
				result = CT_FAILED;
				break;
			}

			evt->dtime = tb->dtime;

			tmp = CT_MALLOC(size);

			if (tmp == NULL)
			{
				CT_LOG(CT_PANIC, "Out of memory");
				delete_ct_midi_event(&evt);
				result = CT_FAILED;
				break;
			}

			CT_MEMCPY(tmp, metadata, size);

			ct_midi_event_set_sysex_LOCAL(evt, type, tmp, size, TRUE);
			ct_track_add_event(track, evt);
			tb->dtime = 0;
		}
		break;

		case MIDI_MARKER:
			break;

		case MIDI_CUE_POINT:
			break; /* don't care much for text events */

		case MIDI_EOT:
			if (tb->varlen != 0)
			{
				CT_LOG(CT_ERR, "Invalid length for EndOfTrack event");
				result = CT_FAILED;
				break;
			}

			tb->eot = 1;
			evt = new_ct_midi_event();

			if (evt == NULL)
			{
				CT_LOG(CT_ERR, "Out of memory");
				result = CT_FAILED;
				break;
			}

			evt->dtime = tb->dtime;
			evt->type = MIDI_EOT;
			ct_track_add_event(track, evt);
			tb->dtime = 0;
			break;

		case MIDI_SET_TEMPO:
			if (tb->varlen != 3)
			{
				CT_LOG(CT_ERR,
					"Invalid length for SetTempo meta event");
				result = CT_FAILED;
				break;
			}

			tempo = (metadata[0] << 16) + (metadata[1] << 8) + metadata[2];
			if (iaDesiredBPM > 0 )
			{
				int iDesiredTempo = (60000000L / iaDesiredBPM);
				if (iDesiredTempo != tempo)
				{
					tb->buffer[tb->buf_pos-3] = metadata[0] = (iDesiredTempo & 0x00FF0000) >> 16;
					tb->buffer[tb->buf_pos - 2] = metadata[1] = (iDesiredTempo & 0x0000FF00) >> 8;
					tb->buffer[tb->buf_pos - 1] = metadata[2] = (iDesiredTempo & 0x000000FF) >> 0;
					tempo = (metadata[0] << 16) + (metadata[1] << 8) + metadata[2];
				}
			}

			evt = new_ct_midi_event();

			if (evt == NULL)
			{
				CT_LOG(CT_ERR, "Out of memory");
				result = CT_FAILED;
				break;
			}

			evt->dtime = tb->dtime;
			evt->type = MIDI_SET_TEMPO;
			evt->channel = 0;
			evt->param1 = tempo;
			evt->param2 = 0;
			ct_track_add_event(track, evt);
			tb->dtime = 0;
			break;

		case MIDI_SMPTE_OFFSET:
			if (tb->varlen != 5)
			{
				CT_LOG(CT_ERR,
					"Invalid length for SMPTE Offset meta event");
				result = CT_FAILED;
				break;
			}

			break; /* we don't use smtp */

		case MIDI_TIME_SIGNATURE:
			if (tb->varlen != 4)
			{
				CT_LOG(CT_ERR,
					"Invalid length for TimeSignature meta event");
				result = CT_FAILED;
				break;
			}

			nominator = metadata[0];
			denominator = pow(2.0, (double)metadata[1]);
			clocks = metadata[2];
			notes = metadata[3];

			break;

		case MIDI_KEY_SIGNATURE:
			if (tb->varlen != 2)
			{
				CT_LOG(CT_ERR,
					"Invalid length for KeySignature meta event");
				result = CT_FAILED;
				break;
			}

			/* We don't care about key signatures anyway */
			/* sf = metadata[0];
			mi = metadata[1]; */
			break;

		case MIDI_SEQUENCER_EVENT:
			break;

		default:
			break;
		}

		if (dyn_buf)
		{
			CT_FREE(dyn_buf);
		}

		return result;

	}
	else     /* channel messages */
	{

		type = status & 0xf0;
		channel = status & 0x0f;

		/* all channel message have at least 1 byte of associated data */
		if ((param1 = ct_midi_file_getc(tb)) < 0)
		{
			CT_LOG(CT_ERR, "Unexpected end of file");
			return CT_FAILED;
		}

		switch (type)
		{

		case NOTE_ON:
		{
			if ((param2 = ct_midi_file_getc(tb)) < 0)
			{
				CT_LOG(CT_ERR, "Unexpected end of file");
				return CT_FAILED;
			}

			if (bpaSupportedChannels && !bpaSupportedChannels[channel] && param2 > 0 )
			{
				// Update the original buffer to remove this chnanel note.
				param2 = 0;
				tb->buffer[tb->buf_pos - 1] = 0;
			}
		}
		break;

		case NOTE_OFF:
			if ((param2 = ct_midi_file_getc(tb)) < 0)
			{
				CT_LOG(CT_ERR, "Unexpected end of file");
				return CT_FAILED;
			}

			break;

		case KEY_PRESSURE:
			if ((param2 = ct_midi_file_getc(tb)) < 0)
			{
				CT_LOG(CT_ERR, "Unexpected end of file");
				return CT_FAILED;
			}

			break;

		case CONTROL_CHANGE:
			if ((param2 = ct_midi_file_getc(tb)) < 0)
			{
				CT_LOG(CT_ERR, "Unexpected end of file");
				return CT_FAILED;
			}

			break;

		case PROGRAM_CHANGE:
			break;

		case CHANNEL_PRESSURE:
			break;

		case PITCH_BEND:
			if ((param2 = ct_midi_file_getc(tb)) < 0)
			{
				CT_LOG(CT_ERR, "Unexpected end of file");
				return CT_FAILED;
			}

			param1 = ((param2 & 0x7f) << 7) | (param1 & 0x7f);
			param2 = 0;
			break;

		default:
			/* Can't possibly happen !? */
			CT_LOG(CT_ERR, "Unrecognized MIDI event");
			return CT_FAILED;
		}

		evt = new_ct_midi_event();

		if (evt == NULL)
		{
			CT_LOG(CT_ERR, "Out of memory");
			return CT_FAILED;
		}

		evt->dtime = tb->dtime;
		evt->type = type;
		evt->channel = channel;
		evt->param1 = param1;
		evt->param2 = param2;
		ct_track_add_event(track, evt);
		tb->dtime = 0;
	}

	return CT_OK;
}




//------------------------------------------------------------------------------------
//
int CMidiFileHelper::ct_midi_file_load_tracks()
{
	ct_return_val_if_fail(clp_MidiFile != NULL, CT_FAILED);

	for (int i = 0; i < clp_MidiFile->ntracks; i++)
	{
		if (ct_midi_file_read_track(i) != CT_OK)
			return CT_FAILED;
	}

	return CT_OK;
}



//------------------------------------------------------------------------------------
//
int CMidiFileHelper::ct_midi_file_read_tracklen()
{
	ct_return_val_if_fail(clp_MidiFile != NULL, CT_FAILED);

	unsigned char length[5];

	if (ct_midi_file_read(clp_MidiFile, length, 4) != CT_OK)
	{
		return CT_FAILED;
	}

	clp_MidiFile->tracklen = ct_getlength(length);
	return CT_OK;
}


/*
 * ct_midi_file_eot
 */
int CMidiFileHelper::ct_midi_file_eot(ct_midi_trackevent_buf* tb)
{
	return tb->eot || (tb->buf_pos >= tb->buf_len);
}




/*
 * Gets the next byte in a MIDI file, taking into account previous running status.
 *
 * returns -1 if EOF or read error
 */
int CMidiFileHelper::ct_midi_file_getc(ct_midi_trackevent_buf* tb)
{
	unsigned char c;

	if (tb->c >= 0)
	{
		c = tb->c;
		tb->c = -1;
	}
	else
	{
		if (tb->buf_pos >= tb->buf_len)
		{
			tb->eof = TRUE;
			return -1;
		}

		c = tb->buffer[tb->buf_pos++];
	}

	return (int)c;
}

/*
 * Saves a byte to be returned the next time ct_midi_file_getc() is called,
 * when it is necessary according to running status.
 */
int CMidiFileHelper::ct_midi_file_push(ct_midi_trackevent_buf* tb, int c)
{
	tb->c = c;
	return CT_OK;
}


void CMidiFileHelper::ct_midi_event_set_sysex_LOCAL(ct_midi_event_t* evt, int type, void* data, int size, int dynamic)
{
	evt->type = type;
	evt->paramptr = data;
	evt->param1 = size;
	evt->param2 = dynamic;
}


/*
 * ct_midi_file_read_varlen
 */
int CMidiFileHelper::ct_midi_file_read_varlen(ct_midi_trackevent_buf* tb)
{
	int i;
	int c;
	tb->varlen = 0;

	for (i = 0;; i++)
	{
		if (i == 4)
		{
			CT_LOG(CT_ERR, "Invalid variable length number");
			return CT_FAILED;
		}

		c = ct_midi_file_getc(tb);

		if (c < 0)
		{
			CT_LOG(CT_ERR, "Unexpected end of file");
			return CT_FAILED;
		}

		if (c & 0x80)
		{
			tb->varlen |= (int)(c & 0x7F);
			tb->varlen <<= 7;
		}
		else
		{
			tb->varlen += c;
			break;
		}
	}

	return CT_OK;
}




//------------------------------------------------------------------------------------
//
int CMidiFileHelper::ct_midi_file_read_track(int num)
{
	ct_return_val_if_fail(clp_MidiFile != NULL, CT_FAILED);

	ct_track_t* track;
	unsigned char id[5], length[5];
	int found_track = 0;
	int skip;

	if (ct_midi_file_read(clp_MidiFile, id, 4) != CT_OK)
	{
		return CT_FAILED;
	}

	id[4] = '\0';


	while (!found_track)
	{
		if (ct_isasciistring((char*)id) == 0)
		{
			CT_LOG(CT_ERR,
				"An non-ascii track header found, corrupt file");
			return CT_FAILED;

		}
		else if (CT_STRCMP((char*)id, "MTrk") == 0)
		{
			const int niTrackStartPos = clp_MidiFile->buf_pos - 4; // For "MTrk"
			found_track = 1;

			if (ct_midi_file_read_tracklen() != CT_OK)
			{
				return CT_FAILED;
			}

			track = new_ct_track(num);
			if (track == NULL)
			{
				CT_LOG(CT_ERR, "Out of memory");
				return CT_FAILED;
			}

			track->i_EventStartPosInTrack = clp_MidiFile->buf_pos - niTrackStartPos;
			track->i_TrackLenght = clp_MidiFile->tracklen ; // For additional info like track start marker / track len variable.
			track->i_TrackStartPos = niTrackStartPos;


			// Now lets create the buffer for the track parsing
			auto track_buffer = new_ct_midi_trackevent_buf(&clp_MidiFile->buffer[clp_MidiFile->buf_pos], clp_MidiFile->tracklen);
			while (!ct_midi_file_eot(track_buffer))
			{
				if (ct_midi_file_read_event(track_buffer, track) != CT_OK)
				{
					delete_ct_track(&track);
					delete_ct_midi_trackevent_buf(&track_buffer);
					return CT_FAILED;
				}
			}

			delete_ct_midi_trackevent_buf(&track_buffer);

			// Now lets skip the track buffer in our master buffer as we donot need it and have parsed locally. 
			if (ct_midi_file_skip(clp_MidiFile, clp_MidiFile->tracklen ) != CT_OK)
			{
				delete_ct_track(&track);
				return CT_FAILED;
			}

			if (ct_midi_file_add_track(clp_MidiFile, track) != CT_OK)
			{
				delete_ct_track(&track);
				return CT_FAILED;
			}
		}
		else
		{
			found_track = 0;

			if (ct_midi_file_read(clp_MidiFile, length, 4) != CT_OK)
			{
				return CT_FAILED;
			}

			skip = ct_getlength(length);

			/* fseek(mf->fp, skip, SEEK_CUR); */
			if (ct_midi_file_skip(clp_MidiFile, skip) != CT_OK)
			{
				return CT_FAILED;
			}
		}
	}

	if (ct_midi_file_eof(clp_MidiFile))
	{
		CT_LOG(CT_ERR, "Unexpected end of file");
		return CT_FAILED;
	}

	return CT_OK;
}










//------------------------------------------------------------------------------------
//
bool CMidiFileHelper::fnInitialiseHelper(std::string claSFilePath)
{
	// delete the older file.
	delete_ct_midi_file(&clp_MidiFile);

	char* buffer = NULL;
	size_t buffer_length = 0;

	{
		ct_file fp;
		/* This file is specified by filename; load the file from disk */

		/* Read the entire contents of the file into the buffer */
		if ((0 != CT_FOPEN_S(&fp, claSFilePath.c_str(), "rb")) || !fp)
		{
			CT_LOG(CT_ERR, "Couldn't open the MIDI file");
			return false;
		}

		buffer = ct_file_read_full(fp, &buffer_length);

		CT_FCLOSE(fp);

		if (buffer == NULL)
			return false;
	}

	clp_MidiFile = new_ct_midi_file(buffer, buffer_length);
	if (NULL == clp_MidiFile)
	{
		CT_FREE(buffer);
		return false;
	}

	if (ct_midi_file_load_tracks() != CT_OK)
	{
		delete_ct_midi_file(&clp_MidiFile);
		return false;
	}


	// We have successfully readed the file. Hence return true..
	return true;
}




static std::string get_channel_used_string(char* cpaFlags, int iaCount)
{
	std::string clRetStr;
	for (int iI = 0; iI < iaCount; iI++)
	{
		if (0 == cpaFlags[iI])
			continue;

		char buff[32];
		if (clRetStr.size() < 1)
			snprintf(buff, sizeof(buff), "%d", iI);
		else
			snprintf(buff, sizeof(buff), ", %d", iI);

		clRetStr += buff;
	}

	return clRetStr;
}

//------------------------------------------------------------------------------------
//
void CMidiFileHelper::fnDisplaySettings()
{
	if (!clp_MidiFile)
	{
		CT_LOG(CT_ERR, "No valid Midi file is loaded");
		return;
	}

	CT_LOG(CT_INFO, "*****************   FILE INFO   ************************");
	CT_LOG(CT_INFO, "File Type        : %d", clp_MidiFile->type);
	CT_LOG(CT_INFO, "Number of Tracks : %d", clp_MidiFile->ntracks);
	// Now lets write the channels that were used in this file.
	{
		std::string clChannelUsed = get_channel_used_string(&clp_MidiFile->bp_ChannelUsed[0], MAX_NUMBER_OF_CHANNELS);
		if (!clChannelUsed.empty())
			CT_LOG(CT_INFO, "Channels used : %s", clChannelUsed.c_str());
	}
	CT_LOG(CT_INFO, "");

	// Now lets fetch the track details.
	for (int iI = 0; iI < clp_MidiFile->ntracks; iI++)
	{
		if (clp_MidiFile->clpp_Track[iI])
			fnDisplayTrackSettings(clp_MidiFile->clpp_Track[iI]);
	}
}




//------------------------------------------------------------------------------------
// Added by AmitRungta on 18-09-2020
//
void CMidiFileHelper::fnDisplayTrackSettings(ct_track_t* clpaTrack)
{
	if (!clpaTrack)
		return;

	CT_LOG(CT_INFO, "--------------------------------------------------------");
	CT_LOG(CT_INFO, "\tTrack Number : %d", clpaTrack->num);
	if (clpaTrack->name)
		CT_LOG(CT_INFO, "\tTrack Name   : %s", clpaTrack->name);
	//CT_LOG(CT_INFO, "\tTrack Start Pos : %d", clpaTrack->i_TrackStartPos);
	//CT_LOG(CT_INFO, "\tTrack Event start position : %d", clpaTrack->i_EventStartPosInTrack);
	//CT_LOG(CT_INFO, "\tTrack Length : %d", clpaTrack->i_TrackLenght);

	// Now lets parse all the channels and the Program change event for this track.
	int iDefaultChannel = -1;
	auto track_event = clpaTrack->first;
	while (track_event && (MIDI_EOT != track_event->type))
	{
		if ( PROGRAM_CHANGE == track_event->type )
		{
			CT_LOG(CT_INFO, "\t\tProgram changed for Channel(%d) to : %s (%d)", track_event->channel, fnGetInstrumentName(track_event->param1).c_str(), track_event->param1);
			iDefaultChannel = track_event->channel;
		}
		else if (iDefaultChannel < 0 && NOTE_ON == track_event->type)
		{
			CT_LOG(CT_INFO, "\t\tDefault Channel to : %d", track_event->channel);
			iDefaultChannel = track_event->channel;
		}

		track_event = track_event->next;
	}

	// Now lets write the channels that were used in this track.
	{
		std::string clChannelUsed = get_channel_used_string(&clpaTrack->bp_ChannelUsed[0], MAX_NUMBER_OF_CHANNELS);
		if (clChannelUsed.empty())
		{
			CT_LOG(CT_INFO, "\tNo channels used in this Track");
		}
		else
		{
			CT_LOG(CT_INFO, "\tChannels used in Track : %s" , clChannelUsed.c_str());
		}
	}

	CT_LOG(CT_INFO, "");
}


//------------------------------------------------------------------------------------
//
char* CMidiFileHelper::fnGenerateFileForChannel(int iaChannelNo, int iaDesiredBPM , int& iarBufferSize)
{
	if (!clp_MidiFile)
	{
		CT_LOG(CT_ERR, "No valid Midi file is loaded");
		return nullptr;
	}

	if (iaChannelNo < 0 || iaChannelNo >= MAX_NUMBER_OF_CHANNELS)
	{
		CT_LOG(CT_ERR, "Selected channel number is not in Valid range");
		return nullptr;
	}

	// Now check if the midi file contains the channel data or not.
	if (!clp_MidiFile->bp_ChannelUsed[iaChannelNo])
	{
		CT_LOG(CT_ERR, "Selected channel doesnot contain any valid data for playing. Select a valid channel number.");
		return nullptr;
	}

	// Now lets create a list of all the tracks whose data needs to be copied to the desired output.
	std::vector < ct_track_t*> clTracksToUseVector;
	for (int iI = 0; iI < clp_MidiFile->ntracks; iI++)
	{
		auto track = clp_MidiFile->clpp_Track[iI];
		if (!track)
			continue;

		bool bUseChannel = false;
		if ( track->bp_ChannelUsed[iaChannelNo])
		{
			bUseChannel = true;
		}
		else
		{
			// This track should not have any valid channel data. Should just contain global data. then add it.
			bool bContainsData = false;
			for (int iCha = 0; iCha < MAX_NUMBER_OF_CHANNELS; iCha++)
				bContainsData |= ( 0 != track->bp_ChannelUsed[iCha]);
			if (!bContainsData)
				bUseChannel = true;
		}

		if (bUseChannel)
			clTracksToUseVector.push_back(track);
	}

	if (clTracksToUseVector.size() < 1)
	{
		_ASSERT(FALSE);
		CT_LOG(CT_ERR, "Error in processing the MIDI file for channels.");
		return nullptr;
	}

	iarBufferSize = MIDI_FILE_HEADER_SIZE;
	for (auto track : clTracksToUseVector)
		iarBufferSize += ( track->i_EventStartPosInTrack + track->i_TrackLenght ) ;

	char* cpRetBuffer = (char*)CT_MALLOC(iarBufferSize);

	// Now lets first copy the Header after modifying the track number count.
	char* cpCurBuffer = cpRetBuffer;
	{
		// First copy the buffer as it is.
		CT_MEMCPY(cpCurBuffer, clp_MidiFile->buffer, MIDI_FILE_HEADER_SIZE);

		// Now lets update the track number count.
		int16_t trackCount = clTracksToUseVector.size();

		cpCurBuffer[11] = (unsigned)(trackCount & 0x00ff);
		cpCurBuffer[10] = (unsigned)( (trackCount & 0xff00) >> 8 ) ;

		cpCurBuffer += MIDI_FILE_HEADER_SIZE;
	}

	// Now lets copy the tracks one by one.
	for (auto track : clTracksToUseVector)
	{
		auto cpRet = fnCopyTrackDataForChannel(cpCurBuffer, track, iaChannelNo, iaDesiredBPM );
		if (cpRet == cpRetBuffer)
		{
			_ASSERT(FALSE);
			CT_FREE(cpRetBuffer);
			CT_LOG(CT_ERR, "Error in processing the MIDI file for channels.");
			return nullptr;
		}
		cpCurBuffer = cpRet;
	}

	return cpRetBuffer;
}




//------------------------------------------------------------------------------------
//
char* CMidiFileHelper::fnCopyTrackDataForChannel(char* cpInputBuf, ct_track_t* orgtrack, int iaChannelNo, int iaDesiredBPM)
{
	auto cpCurBuffer = cpInputBuf;

	// Now check if any other channel than the current one is selected then do special processing oherwise copy the buffer directly.
	bool bContainsOtherChannelData = false;
	for (int iCha = 0; iCha < MAX_NUMBER_OF_CHANNELS; iCha++)
	{
		if (orgtrack->bp_ChannelUsed[iCha] && iCha != iaChannelNo)
		{
			bContainsOtherChannelData = true;
			break;
		}
	}

	// Now lets first of all copy the complete buffer..
	{
		char* cpSrcBuf = &clp_MidiFile->buffer[orgtrack->i_TrackStartPos];
		CT_MEMCPY(cpCurBuffer, cpSrcBuf, (orgtrack->i_EventStartPosInTrack + orgtrack->i_TrackLenght) );
	}

	// Now check if we need to remove the other channel data here...
	if (bContainsOtherChannelData || iaDesiredBPM > 0 )
	{
		auto temp_track = new_ct_track(orgtrack->num);
		temp_track->i_EventStartPosInTrack = orgtrack->i_EventStartPosInTrack;
		temp_track->i_TrackLenght = orgtrack->i_TrackLenght; // For additional info like track start marker / track len variable.
		temp_track->i_TrackStartPos = 0;

		bool bpSupportedChannels[MAX_NUMBER_OF_CHANNELS];
		for (int iI = 0; iI < MAX_NUMBER_OF_CHANNELS; iI++)
			bpSupportedChannels[iI] = false;
		bpSupportedChannels[iaChannelNo] = true;


		// Lets update the buffer to remove extra channels.
		auto track_buffer = new_ct_midi_trackevent_buf(&cpCurBuffer[temp_track->i_EventStartPosInTrack], temp_track->i_TrackLenght);
		while (!ct_midi_file_eot(track_buffer))
		{
			if (ct_midi_file_read_event(track_buffer, temp_track, &bpSupportedChannels[0] , iaDesiredBPM ) != CT_OK)
			{
				delete_ct_track(&temp_track);
				delete_ct_midi_trackevent_buf(&track_buffer);
				return cpInputBuf;
			}
		}

		delete_ct_midi_trackevent_buf(&track_buffer);
	}

	// as we have added this much buffer.
	cpCurBuffer += (orgtrack->i_EventStartPosInTrack + orgtrack->i_TrackLenght);
	return cpCurBuffer;
}