from conans import ConanFile, CMake


class BitshowConan(ConanFile):
    scm = {
        "type": "git",
        "subfolder": "bitshow",
        "url": "auto",
        "revision": "auto"
    }
    name = "bitshow"
    version = "2.0.0"
    license = "MIT"
    author = "kaiyin kindlychung@gmail.com"
    url = "https://github.com/kindlychung/bitshow"
    description = "a c++ library for dissecting floating point numbers"
    topics = ("float", "double", "binary representation")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False]}
    default_options = "shared=False"
    generators = "cmake"
    exports_sources = "src/*.cpp", "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.hpp", dst="include", src="src")
        self.copy("*.h", dst="include", src="src")
        self.copy("*.lib", dst="lib", keep_path=False)
        self.copy("*.dll", dst="bin", keep_path=False)
        self.copy("*.dylib*", dst="lib", keep_path=False)
        self.copy("*.so", dst="lib", keep_path=False)
        self.copy("*.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["bitshow"]
