#pragma once


#include <string>
#include "MidiHelperData.h"









//------------------------------------------------------------------------------------
// Added by AmitRungta For implementing the Midi File Reader 
//
class CMidiFileHelper
{
public :
	CMidiFileHelper();
	~CMidiFileHelper();


public :
	bool fnInitialiseHelper(std::string claSFilePath);
	void fnDisplaySettings();
	char* fnGenerateFileForChannel(int iaChannelNo, int iaDesiredBPM, int& iarBufferSize);


protected :
	void fnDisplayTrackSettings(ct_track_t* clpaTrack);
	char* fnCopyTrackDataForChannel( char* cpInputBuf, ct_track_t* track, int iaChannelNo, int iaDesiredBPM);

protected :
	int ct_midi_file_load_tracks();
	int ct_midi_file_read_track(int num);
	int ct_midi_file_read_tracklen();
	int ct_midi_file_eot(ct_midi_trackevent_buf* tb);


protected :
	ct_midi_file* clp_MidiFile;



protected:
	// TO generate the Midid file data from the buffer..
	static ct_midi_file* new_ct_midi_file(char* buffer, size_t length);
	static char* ct_file_read_full(ct_file fp, size_t* length);
	static void delete_ct_midi_file(ct_midi_file** pmf);

	static ct_midi_trackevent_buf* new_ct_midi_trackevent_buf(char* buffer, size_t length);
	static void delete_ct_midi_trackevent_buf(ct_midi_trackevent_buf** pmf);

	static int ct_midi_file_read(ct_midi_file* mf, void* buf, int len);
	static int ct_midi_file_read(ct_midi_trackevent_buf* tb, void* buf, int len);


	static int ct_midi_file_read_mthd(ct_midi_file* midifile);
	static int ct_midi_file_add_track(ct_midi_file* mf, ct_track_t* track);

	static int ct_midi_file_skip(ct_midi_file* mf, int len);
	static int ct_midi_file_eof(ct_midi_file* mf);
	static int ct_isasciistring(char* s);
	static long ct_getlength(unsigned char* s);



	static ct_midi_event_t* new_ct_midi_event();
	static void delete_ct_midi_event(ct_midi_event_t** pevt);


	static ct_track_t* new_ct_track(int num);
	static void delete_ct_track(ct_track_t** ptrack);
	static int ct_track_set_name(ct_track_t* track, char* name);
	static int ct_track_add_event(ct_track_t* track, ct_midi_event_t* evt);


	static int ct_midi_file_read_event(ct_midi_trackevent_buf* tb, ct_track_t* track , bool* bpaSupportedChannels = nullptr, int iaDesiredBPM = -1 );
	static int ct_midi_file_read_varlen(ct_midi_trackevent_buf* tb);
	static int ct_midi_file_getc(ct_midi_trackevent_buf* tb);
	static int ct_midi_file_push(ct_midi_trackevent_buf* tb, int c);


	static void ct_midi_event_set_sysex_LOCAL(ct_midi_event_t* evt, int type, void* data, int size, int dynamic);


public:


	// Helper function to get the selected instrument name.
	static std::string fnGetInstrumentName(int iaProgID);

	// Check if the file is a valid midi file or not.
	static int ct_is_midifile(std::string claSFileName );
};

