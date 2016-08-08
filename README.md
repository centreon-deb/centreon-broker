Build instructions for the impatient


```bash
curl https://raw.githubusercontent.com/centreon-deb/centreon-broker/debian/bootstrap | sh
cd centreon-broker && git deb-pkg -C -U -u 2.11.4 -d origin/debian build
```

Further instruction in the [README.Build.md](README.Build.md) file.
