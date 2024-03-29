.PHONY: compile
compile:
	docker run -it --rm -v "${PWD}":/src sgdk:${SGDK_VERSION}

compile-native:
	make -f SGDK/makefile.gen

SGDK_VERSION=1.90
download:
	if ! test -d SGDK; then git clone https://github.com/Stephane-D/SGDK && cd SGDK && git checkout tags/v${SGDK_VERSION} ; fi

build-sgdk:	download
	cd SGDK && docker build . -t sgdk:${SGDK_VERSION}

rm-sgdk:
	rm -rf SGDK

shell:
	docker run -it --rm -v "${PWD}":/src --entrypoint=/bin/bash sgdk:${SGDK_VERSION} 

clean:	rm-sgdk
	rm -rf out/*