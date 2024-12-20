#include "entity.hpp"

json Entity::Serialise() const
{
    return json{
            {"createdAt", created_at}
        };
}

std::string Entity::GetCreatedAt() const
{
    return created_at;
}
