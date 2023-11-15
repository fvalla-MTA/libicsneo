#ifndef __VSA07_H__
#define __VSA07_H__

#ifdef __cplusplus

#include "icsneo/disk/vsa/vsa.h"

#include <vector>

namespace icsneo {

/**
 * Class that holds data for an internal/debug VSA record
 */
class VSA07 : public VSA {
public:
	/**
	 * Constructor to convert bytestream into internal/debug record
	 *
	 * @param bytes Bytestream to parse into internal/debug record
	 */
	VSA07(uint8_t* const bytes);

	/**
	 * Get the timestamp for this record in 25 nanosecond ticks since January 1, 2007
	 *
	 * @return The timestamp for this record in 25 nanosecond ticks since January 1, 2007
	 */
	uint64_t getTimestamp() override { return timestamp; }

private:
	/**
	 * Perform the checksum on this record
	 *
	 * @param bytes Bytestream to test against the checksum
	 */
	void doChecksum(uint8_t* bytes) override;

	uint32_t lastSector; // Unknown
	uint32_t currentSector; // Unknown
	std::vector<uint8_t> reserved; // Unused bytes (12 bytes)
	uint64_t timestamp; // Timestamp for this record in 25 nanosecond ticks since January 1, 2007
	uint16_t checksum; // Sum of the previous 15 words
};

} // namespace icsneo

#endif // __cplusplus
#endif // __VSA07_H__