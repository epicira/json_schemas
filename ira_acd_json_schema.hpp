#pragma once

namespace IraACD
{
inline constexpr const char *C_AddCallSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_add_call"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "queue_id": {"type": "string"},
                "call_uuid": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "queue_id", "call_uuid"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_AgentEventSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::agent_event"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"},
                "agent_id": {"type": "string"},
                "event": {"type": "integer"},
                "state": {"type": "integer"}
            },
            "additionalProperties": false,
            "required": ["tenant_id", "agent_id", "event"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_GetCallsSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "event_name": {"type": "string", "enum": ["acd::request_get_calls"]},
        "event_data": {
            "type": "object",
            "properties": {
                "tenant_id": {"type": "string"}
            },
            "additionalProperties": false,
            "required": ["tenant_id"]
        }
    },
    "additionalProperties": false,
    "required": ["event_name", "event_data"]
})";

inline constexpr const char *C_ConfigFileSchema = R"({
    "$schema": "http://json-schema.org/draft-07/schema#",
    "type": "object",
    "properties": {
        "file_store_base_url": {"type": "string", "description": "File Store URL where audio for the queue handling is stored"}
    },
    "required": ["file_store_base_url"]
})";
} // namespace IraACD
