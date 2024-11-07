#include <algorithm>
#include <concepts>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace Passwd {
struct Locked;
struct UnLocked;

template < bool >
struct _DefaultManager;

template <>
struct _DefaultManager< false > {};

template <>
struct _DefaultManager< true > {
    friend struct Locked;
    friend struct UnLocked;

  protected:
    std::vector< std::string > passwds;

  public:
    _DefaultManager() { std::cout << "Default Manager Created" << std::endl; }

    _DefaultManager(_DefaultManager&&) {
        std::cout << "&& Manager Created" << std::endl;
    }

    consteval static auto version() { return "v1.0.0"; }

    void list_passwd() const {
        std::for_each(passwds.begin(), passwds.end(),
          [](const auto& passwd) { std::cout << passwd << std::endl; });
    }

    decltype(auto) operator=(const _DefaultManager< false >&) {}
};

struct Locked : public _DefaultManager< true > {
    Locked(_DefaultManager& mgr) {
        std::cout << "Locked construct\n";
        this->passwds = mgr.passwds;
    }

    Locked(_DefaultManager&& mgr) : _DefaultManager{std::move(mgr)} {
        std::cout << "Locked && construct\n";
        this->passwds = std::move(mgr.passwds);
    }
};

struct UnLocked : public _DefaultManager< true > {
    UnLocked(_DefaultManager& mgr) {
        std::cout << "Locked construct\n";
        this->passwds = mgr.passwds;
    }

    UnLocked(_DefaultManager&& mgr) : _DefaultManager{std::move(mgr)} {
        std::cout << "UnLocked && construct\n";
    }

    void insert(const std::string_view pass) {
        this->passwds.push_back(std::string{pass});
    }
};

template < typename Manager >
concept ManagerConcept = requires(Manager m) {
    {
        m.version()
    } -> std::convertible_to< std::string_view >;
    {
        m.list_passwd()
    };

    m = _DefaultManager< false >{};
};

namespace mgr {

decltype(auto) New() { return _DefaultManager< true >{}; }

template < ManagerConcept Mgr, bool NoValid = false >
auto Lock(Mgr&& mgr) {
    auto res = Locked{std::forward< _DefaultManager< true > >(mgr)};
    mgr      = _DefaultManager< NoValid >{};
    return res;
}

template < ManagerConcept Mgr, bool NoValid = false >
auto UnLock(Mgr&& mgr) {
    auto res = UnLocked{std::forward< _DefaultManager< true > >(mgr)};
    mgr      = _DefaultManager< NoValid >{};
    return res;
}

} // namespace mgr

} // namespace Passwd

int main() {
    auto passmgr = Passwd::mgr::New();

    std::cout << "Version: " << passmgr.version() << std::endl;

    auto unLockPasswdMgr = Passwd::mgr::UnLock(std::move(passmgr));
    unLockPasswdMgr.list_passwd();
    unLockPasswdMgr.insert("Hey");
    unLockPasswdMgr.insert("1");
    unLockPasswdMgr.insert("2");
    unLockPasswdMgr.list_passwd();

    // auto lockPasswdMgr = Passwd::mgr::Lock(std::move(unLockPasswdMgr));

    // lockPasswdMgr.list_passwd();

    return 0;
}
