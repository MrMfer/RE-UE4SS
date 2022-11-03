#include <LuaType/LuaFSoftObjectPath.hpp>
#include <LuaType/LuaFName.hpp>
#include <LuaType/LuaFString.hpp>
#include <DynamicOutput/DynamicOutput.hpp>
#include <Helpers/String.hpp>

namespace RC::LuaType
{
    FSoftObjectPath::FSoftObjectPath(Unreal::FSoftObjectPath& object) : LocalObjectBase<Unreal::FSoftObjectPath, FSoftObjectPathName>(std::move(object)) {}

    auto FSoftObjectPath::construct(const LuaMadeSimple::Lua& lua, Unreal::FSoftObjectPath& unreal_object) -> const LuaMadeSimple::Lua::Table
    {
        LuaType::FSoftObjectPath lua_object{unreal_object};

        LuaMadeSimple::Lua::Table table = lua.prepare_new_table();

        setup_member_functions<LuaMadeSimple::Type::IsFinal::Yes>(table);

        setup_metamethods(lua_object);

        // Create object & surrender ownership to Lua
        lua.transfer_stack_object(std::move(lua_object), "FSoftObjectPathUserdata", lua_object.get_metamethods());

        return table;
    }

    auto FSoftObjectPath::construct(const LuaMadeSimple::Lua& lua, BaseObject& construct_to) -> const LuaMadeSimple::Lua::Table
    {
        LuaMadeSimple::Lua::Table table = lua.prepare_new_table();

        setup_member_functions<LuaMadeSimple::Type::IsFinal::No>(table);

        setup_metamethods(construct_to);

        return table;
    }

    auto FSoftObjectPath::setup_metamethods(BaseObject& base_object) -> void
    {

    }

    template<LuaMadeSimple::Type::IsFinal is_final>
    auto FSoftObjectPath::setup_member_functions(LuaMadeSimple::Lua::Table& table) -> void
    {
        table.add_pair("GetAssetPathName", [](const LuaMadeSimple::Lua& lua) -> int {
            auto& lua_object = lua.get_userdata<FSoftObjectPath>();
            FName::construct(lua, lua_object.get_local_cpp_object().AssetPathName);
            return 1;
        });

        table.add_pair("GetSubPathString", [](const LuaMadeSimple::Lua& lua) -> int {
            auto& lua_object = lua.get_userdata<FSoftObjectPath>();
            FString::construct(lua, &lua_object.get_local_cpp_object().SubPathString);
            return 1;
        });

        if constexpr (is_final == LuaMadeSimple::Type::IsFinal::Yes)
        {
            table.add_pair("type", [](const LuaMadeSimple::Lua& lua) -> int {
                lua.set_string(ClassName::ToString());
                return 1;
            });

            // If this is the final object then we also want to finalize creating the table
            // If not then it's the responsibility of the overriding object to call 'make_global()'
            table.make_global("FSoftObjectPathUserdata");
        }
    }
}