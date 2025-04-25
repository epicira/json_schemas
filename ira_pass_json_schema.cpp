const char* IraPassSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
		"node_license": {"type": "boolean", "enum" : [true,false] },
		"site_private_key_file": {"type": "string"},
		"ira_license_web": {"type": "string", "minLength": 5},
		"use_old_rsa_protocol": {"type": "boolean", "enum" : [true,false] },
		"renewal_frequency": {"type": "integer"}
	}
})";
