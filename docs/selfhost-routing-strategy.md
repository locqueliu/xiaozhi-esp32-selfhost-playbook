# Self-Host Routing Strategy

## Goal

Support a deployment flow where an ESP32 device can safely connect to self-hosted infrastructure without hard-coding private values into a public repository.

## Recommended Inputs

- build-time OTA default
- build-time WebSocket default
- runtime settings payload from the deployment layer
- environment-specific secrets stored outside Git

## Resolution Order

Use the following order when deciding which endpoint to connect to:

1. runtime settings returned by the deployment service
2. build-time fallback defined in configuration
3. fail with a clear log if neither exists

## Clean-Room Logic Pattern

```cpp
std::string ResolveUrl(const std::string& runtime_url, const std::string& fallback_url) {
    if (!runtime_url.empty()) {
        return runtime_url;
    }
    return fallback_url;
}
```

## Recommended Release Hygiene

- store local addresses only in ignored files or CI secrets
- publish placeholder values in examples
- document the upstream repository prominently
- separate notes and examples from production firmware code

## Suggested Repo Split

For public presentation, keep things in three layers:

- upstream fork or private working copy for real firmware development
- documentation repo like this one for portfolio-safe writeups
- deployment or infra repo kept private if it contains internal services
