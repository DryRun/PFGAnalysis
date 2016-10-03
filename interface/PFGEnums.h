#ifndef PFGEnums_h
#define PFGEnums_h

namespace pfg {
	enum Detector_t {
		kHBHE,
		kHF,
		kHO
	};

	struct ChannelIndex {
		int ieta,
		int iphi,
		int depth
	}
}


#endif