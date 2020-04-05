Name: zswap-cli
Version: 0.1.0
Release: 1%{?dist}

Summary: Command-line tool to control zswap options
License: MIT
URL: https://github.com/xvitaly/%{name}
Source0: %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: cxxopts-devel
BuildRequires: ninja-build
BuildRequires: fmt-devel
BuildRequires: systemd
BuildRequires: gcc-c++
BuildRequires: cmake

%{?systemd_requires}

%description
ZSwap-cli is a command-line tool to control zswap options.

%prep
%autosetup
mkdir -p %{_target_platform}

%build
pushd %{_target_platform}
    %cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    ..
popd
%ninja_build -C %{_target_platform}

%post
%systemd_post %{name}.service

%preun
%systemd_preun %{name}.service

%postun
%systemd_postun_with_restart %{name}.service

%install
%ninja_install -C %{_target_platform}

%files
%doc README.md
%license LICENSE
%{_sbindir}/%{name}
%{_unitdir}/%{name}.service
%config(noreplace) %{_sysconfdir}/default/%{name}

%changelog
* Sat Apr 04 2020 Vitaly Zaitsev <vitaly@easycoding.org> - 0.1.0-1
- Initial SPEC release.
