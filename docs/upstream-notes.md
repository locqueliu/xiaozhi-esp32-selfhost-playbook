# Upstream Notes

## Confirmed Upstream

- upstream repository: [78/xiaozhi-esp32](https://github.com/78/xiaozhi-esp32)
- license observed: `MIT`
- upstream focus: ESP32-based MCP chatbot implementation

## Customization Theme

The portfolio-safe customization summarized in this repo comes from a common deployment need:

- allow OTA checks to point to a self-hosted service
- allow WebSocket audio or control traffic to point to a self-hosted service
- keep a local fallback URL available when the runtime configuration response does not provide one

## Public-Safe Summary Of The Idea

The implementation direction can be summarized as:

1. add a build-time configuration item for the default WebSocket endpoint
2. keep the default OTA endpoint configurable as well
3. resolve the connection target at runtime
4. if runtime settings are empty, fall back to the configured WebSocket URL

## Why This Matters

This pattern is useful when:

- the device must work in a local network demo
- upstream-managed services are not the target environment
- a team needs stable testing against internal infrastructure
- a public fork should not reveal internal service addresses

## What Is Deliberately Not Published Here

- raw private project files
- internal IP addresses from local development
- secrets, tokens, or account material
- a full patch set copied from a private working tree
