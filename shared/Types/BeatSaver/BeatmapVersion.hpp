#pragma once
#include "../TypeMacros.hpp"
#include "Difficulty.hpp"

namespace BeatSaver {
    class Beatmap;
    class BeatmapVersion;
    namespace API {
        void DownloadBeatmapAsync(const BeatSaver::Beatmap& beatmap, const BeatSaver::BeatmapVersion& beatmapVer, std::function<void(bool)> finished, std::function<void(float)> progressUpdate);
        void GetCoverImageAsync(const BeatSaver::BeatmapVersion& beatmap, std::function<void(std::vector<uint8_t>)> finished, std::function<void(float)> progressUpdate);
    }
}

DECLARE_JSON_CLASS(BeatSaver, BeatmapVersion,
    GETTER_VALUE(std::string, CreatedAt);
    GETTER_VALUE_OPTIONAL(int, SageScore);
    GETTER_VALUE(std::vector<BeatSaver::BeatmapDifficulty>, Diffs);
    GETTER_VALUE_OPTIONAL(std::string, Feedback);
    GETTER_VALUE(std::string, Hash);
    GETTER_VALUE_OPTIONAL(std::string, Key);
    GETTER_VALUE(std::string, State); // Enum with values Uploaded, Testplay, Published, Feedback
    //GETTER_VALUE(BeatSaver::Instant, TestplayAt);
    //GETTER_VALUE(BeatSaver::Testplays, Uploaded);
    GETTER_VALUE(std::string, DownloadURL);
    GETTER_VALUE(std::string, CoverURL);
    GETTER_VALUE(std::string, PreviewURL);
    inline void DownloadBeatmapAsync(const BeatSaver::Beatmap& beatmap, std::function<void(bool)> finished, std::function<void(float)> progressUpdate) {
        BeatSaver::API::DownloadBeatmapAsync(beatmap, *this, finished, progressUpdate);
    }
    inline void GetCoverImageAsync(std::function<void(std::vector<uint8_t>)> finished, std::function<void(float)> progressUpdate) {
        BeatSaver::API::GetCoverImageAsync(*this, finished, progressUpdate);
    }
)
