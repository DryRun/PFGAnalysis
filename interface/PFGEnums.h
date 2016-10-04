#ifndef PFGEnums_h
#define PFGEnums_h

#include <utility>
#include <string>

namespace pfg {
	enum Detector_t {
		kHBHE,
		kHFP,
		kHFM,
		kHO
	};

	static const std::map<Detector_t, std::string> detector_strings= {
		{kHBHE, "HBHE"},
		{kHFP, "HFP"},
		{kHFM, "HFM"},
		{kHO, "HO"},
	};

	struct ChannelIndex {
		int ieta,
		int iphi,
		int depth
	};

	struct DetectorVolume {
		std::pair<int, int> ieta,
		std::pair<int, int> iphi,
		std::pair<int, int> depth
	};

	struct Dummy {
		DetectorVolume MakeDetectorVolume(Detector_t detector) {
			detector_volume = DetectorVolume();
			if (detector == kHBHE) {
				detector_volume.ieta = std::make_pair(-29, 29);
				detector_volume.iphi = std::make_pair(1, 72);
				detector_volume.depth = std::make_pair(1, 4);
			} else if (detector == kHFP) {
				detector_volume.ieta = std::make_pair(29, 41);
				detector_volume.iphi = std::make_pair(1, 72);
				detector_volume.depth = std::make_pair(1, 4);
			} else if (detector == kHFM) {
				detector_volume.ieta = std::make_pair(-41, -29);
				detector_volume.iphi = std::make_pair(1, 72);
				detector_volume.depth = std::make_pair(1, 2);
			} else if (detector == kHO) {
				detector_volume.ieta = std::make_pair(-29, 29);
				detector_volume.iphi = std::make_pair(1, 72);
				detector_volume.depth = std::make_pair(4, 4);
			}
			return detector_volume;
		}
	};

	static const std::map<Detector_t, DetectorVolume> detector_volumes = {
		{kHBHE, Dummy::MakeDetectorVolume(kHBHE)},
		{kHFP, Dummy::MakeDetectorVolume(kHFP)},
		{kHFM, Dummy::MakeDetectorVolume(kHFM)},
		{kHO, Dummy::MakeDetectorVolume(kHO)}
	}

}


#endif