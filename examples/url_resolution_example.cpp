#include <string>

std::string ResolveWebsocketUrl(const std::string& runtime_url,
                                const std::string& fallback_url) {
    if (!runtime_url.empty()) {
        return runtime_url;
    }

    return fallback_url;
}
