const char* ConfFileSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "model_id": {"type": "string", "minLength": 2},
      "model_path": {"type": "string", "minLength": 5},
      "port_number": {"type": "integer", "minimum": 2000},
      "thread_count": {"type": "integer", "minimum": 1},
      "kaldi_core_count": {"type": "integer", "minimum": 2, "maximum": 45}
    },
    "required": ["model_id", "model_path","port_number","kaldi_core_count"]
})";

const char* ASRRequestSchema = R"(
{
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
      "partial": {"type": "boolean", "enum" : [true,false] },
      "details": {"type": "boolean", "enum" : [true,false] },
      "null_partial": {"type": "boolean", "enum" : [true,false] },
      "debug": {"type": "boolean", "enum" : [true,false] },
      "brotli": {"type": "boolean", "enum" : [true,false] },
      "ts": {"type": "integer"},
      "timeout": {"type": "integer"}
    }
})";
