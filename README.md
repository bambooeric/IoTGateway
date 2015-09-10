BUILDING OpenWRT BASE on HI3718

1. Ubuntu 12.0 later Operator system
2. Following below command to setup HOST env

	sudo apt-get install build-essential subversion git-core libncurses5-dev zlib1g-dev gawk flex quilt libssl-dev
	xsltproc libxml-parser-perl mercurial bzr ecj cvs unzip

3. Download latest source code of OpwnWRT

	mkdir -p /openwrt
	cd openwrt
	# Get chaos calmer version
	git clone git://git.openwrt.org/15.05/openwrt.git chaos_calmer

4. update feeds and packages of OpenWRT

	./scripts/feeds update -a
	./scripts/fedds install -a

5. Put target files base on HI3718 into OpenWRT soruce code

	git clone https://github.com/IoTGateway/gateway.git
	tar xvf target-openwrt.tar.gz
	cp -rf * <directory-of-openwrt-sorucecode>

6. make menuconfig, choose target of Hi3718

7. make V=99
