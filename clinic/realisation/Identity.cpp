#include "../include/Identity.h"

Identity::Identity() : category_("unknown") {}

Identity::Identity(const std::string& category) {
    assignCategory(category);
}

void Identity::assignCategory(const std::string& category) {
    category_ = category;
}

std::string Identity::retrieveCategory() const {
    return category_;
}

void Identity::copyFrom(const Identity& other) {
    assignCategory(other.retrieveCategory());
}

bool Identity::isSameAs(const Identity& other) const {
    return category_ == other.retrieveCategory();
}
