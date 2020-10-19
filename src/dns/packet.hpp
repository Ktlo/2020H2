#ifndef DNS_PACKET_HEAD_QPXPPCKFEK
#define DNS_PACKET_HEAD_QPXPPCKFEK

#include <cinttypes>
#include <vector>
#include <memory>

#include <ekutils/bag.hpp>

#include "record.hpp"
#include "question.hpp"
#include "answer.hpp"

namespace ktlo::dns {

class reader;
class writer;

struct packet final {
	struct header final {
		word_t id;
		bool is_response;
		opcodes opcode;
		bool authoritative;
		bool trancated;
		bool reqursion_desired;
		bool recursion_available;
		byte_t Z;
		rcodes rcode;
	} head;

	typedef std::vector<answer> record_list;

	std::vector<question> questions;
	record_list answers;
	record_list authority;
	record_list additional;

	void read(namez & ns, const varbytes_view & data);
	void write(const namez & ns, varbytes & data) const;

	std::string to_string() const;

private:
	ekutils::bag<std::unique_ptr<record>> all;

	void read_records(reader & rd, record_list & list, word_t count);
	void write_records(writer & wr, const record_list & list) const;
};

} // ktlo::dns

#endif // DNS_PACKET_HEAD_QPXPPCKFEK
