# Centreon Broker #

Centreon Broker is an extensible open-source monitoring event
transmitter (broker). It is a low-level component of the
[Centreon software suite](https://www.centreon.com).

Centreon Broker is released under the Apache License, Version 2.0
and is endorsed by the [Centreon company](https://www.centreon.com).

## Documentation ##

The full Centreon Broker documentation is available online
[here](http://documentation.centreon.com/docs/centreon-broker/en/). It
is generated from ReST files located in the *./doc/* directory of
Centreon Broker sources.

The documentation extensively covers all aspects of Centreon Broker such
as installation, compilation, configuration, use and more. It is the
reference guide of the software. This *README* is only provided as a
quick introduction.

## Installing from binaries ##

**Warning**: Centreon Broker is a low-level component of the Centreon
software suite. If this is your first installation you would probably
want to [install it entirely](https://documentation.centreon.com/docs/centreon/en/2.6.x/installation/index.html).

Centreon ([the company behind the Centreon software suite](http://www.centreon.com))
provides binary packages for RedHat / CentOS. They are available either
as part of the [Centreon Entreprise Server distribution](https://www.centreon.com/en/products/centreon-enterprise-server/)
or as individual packages on [our RPM repository](https://documentation.centreon.com/docs/centreon/en/2.6.x/installation/from_packages.html).

Once the repository installed a simple command will be needed to install
Centreon Broker.

    $# yum install centreon-broker

## Fetching sources ##

The reference repository is hosted at [GitHub](https://github.com/centreon/centreon-broker).
Beware that the repository hosts in-development sources and that it
might not work at all.

Stable releases are available as gziped tarballs on [Centreon's download site](https://download.centreon.com).

## Compilation (quickstart) ##

**Warning**: Centreon Broker is a low-level component of the Centreon
software suite. If this is your first installation you would probably
want to [install it entirely](https://documentation.centreon.com/docs/centreon/en/2.6.x/installation/index.html).

This paragraph is only a quickstart guide for the compilation of
Centreon Broker. For a more in-depth guide with build options you should
refer to the [online documentation](https://documentation.centreon.com/docs/centreon-broker/en/latest/installation/index.html#using-sources).

Once the sources of Centreon Broker extracted, got to the *./build/*
directory and launch the CMake command. This will look for required
dependencies and print a summary of the compilation parameters if
everything went fine.

    $> cd centreon-broker/build
    $> cmake .
    ...

Now launch the compilation using the *make* command and then install the
software by running *make install* as priviledged user.

    $> make -j 4
    ...
    $# make install

You're done !

## Bug reports ##

The best way to report a bug is to open an issue in GitHub's
[issue tracker](https://github.com/centreon/centreon-broker/issues/).

For a quick resolution your message should contain :

* the problem description
* precise steps on how to reproduce the issue (if you're using Centreon
  web UI tell us where you click)
* the expected behavior
* the Centreon product**s** version**s**
* the operating system you're using (name and version)
* if possible configuration, log and debug files

## Contributing ##

Contributions are much welcome ! If possible provide them as
pull-requests on GitHub. If not, patches will do but describe against
which version/commit they apply.

For any question or remark feel free to send a mail to the project
maintainer : Matthieu Kermagoret (mkermagoret@centreon.com).

## Feature requests ##

Features can be requested in the
[issue tracker](https://github.com/centreon/centreon-broker/issues/).
