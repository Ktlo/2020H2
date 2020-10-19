#ifndef DNS_RECORDS_TXT_HEAD_TRHEDFTVR
#define DNS_RECORDS_TXT_HEAD_TRHEDFTVR

#include <vector>

#include "record.hpp"

namespace ktlo::dns::records {

dns_record(TXT, 16) {
	std::vector<std::string> texts;

	virtual void encode(varbytes & data) const override;
	virtual void decode(const varbytes_view & data) override;
	virtual void read(const YAML::Node & node, const name & zone) override;
	virtual std::string data_to_string() const override;
};

} // ktlo::dns::records

#endif // DNS_RECORDS_TXT_HEAD_TRHEDFTVR
