#ifndef PFGEnums_h
#define PFGEnums_h

#include <utility>
#include <string>

namespace pfg {
	enum Detector_t {
		kHB,
		kHE,
		kHF,
		kHO
	};

	static const std::map<Detector_t, std::string> detector_strings= {
		{kHB, "HB"},
		{kHE, "HE"},
		{kHF, "HF"},
		{kHO, "HO"},
	};

	struct ChannelIndex {
		int ieta;
		int iphi;
		int depth;
		ChannelIndex(int p_ieta, int p_iphi, int p_depth) : ieta(p_ieta), iphi(p_iphi), depth(p_depth) {};
	};

	struct DetectorVolume {
		std::pair<int, int> ieta;
		std::pair<int, int> iphi;
		std::pair<int, int> depth;
		DetectorVolume(int ieta_min, int ieta_max, int iphi_min, int iphi_max, int depth_min, int depth_max) {
			ieta = std::make_pair(ieta_min, ieta_max);
			iphi = std::make_pair(iphi_min, iphi_max);
			depth = std::make_pair(depth_min, depth_max);
		}
	};

	static const std::map<Detector_t, DetectorVolume> detector_volumes = {
		{kHB, DetectorVolume(-14, 14, 1, 72, 1, 4)},
		{kHE, DetectorVolume(-29, 29, 1, 72, 1, 4)},
		{kHF, DetectorVolume(-41, 41, 1, 72, 1, 2)},
		{kHO, DetectorVolume(-29, 29, 1, 72, 4, 4)}
	};

}


#endif