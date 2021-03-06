%undefine __cmake_in_source_build

Name: zswap-cli
Version: 0.5.0
Release: 1%{?dist}

Summary: Command-line tool to control zswap options
License: MIT
URL: https://github.com/xvitaly/%{name}
Source0: %{url}/archive/v%{version}/%{name}-%{version}.tar.gz

BuildRequires: boost-devel
BuildRequires: cmake
BuildRequires: fmt-devel
BuildRequires: gcc-c++
BuildRequires: glibc-headers
BuildRequires: kernel-headers
BuildRequires: ninja-build
BuildRequires: pandoc
BuildRequires: systemd

%{?systemd_requires}

%description
ZSwap-cli is a command-line tool to control zswap options.

%prep
%autosetup

%build
%cmake -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_DOCS:BOOL=OFF \
    -DBUILD_MANPAGE:BOOL=ON
%cmake_build

%post
%systemd_post %{name}.service

%preun
%systemd_preun %{name}.service

%postun
%systemd_postun_with_restart %{name}.service

%install
%cmake_install

%files
%doc README.md docs/*
%license LICENSE
%{_sbindir}/%{name}
%{_unitdir}/%{name}.service
%{_mandir}/man1/%{name}.*
%dir %{_sysconfdir}/%{name}
%config(noreplace) %{_sysconfdir}/%{name}/%{name}.conf

%changelog
* Thu Apr 01 2021 Vitaly Zaitsev <vitaly@easycoding.org> - 0.5.0-1
- Updated to version 0.5.0.
