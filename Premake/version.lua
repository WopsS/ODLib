Version = {}

Version.Major = 0
Version.Minor = 8
Version.Patch = 0

function Version:format(inputFile)
    local inFile = io.open(inputFile, "r")

    if not inFile then
        return nil
    end

    local outputFile = string.sub(inputFile, 0, string.len(inputFile) - 3)
    local version = Version.Major .. "." .. Version.Minor .. "." .. Version.Patch
    local readOutFile = io.open(outputFile, "r")
    local outFileContent = ""

    if readOutFile then
        outFileContent = readOutFile:read("*a")
        readOutFile:close()
    end
    
    if not string.find(outFileContent, version) then
        local outFile = io.open(outputFile, "w")
        local result = inFile:read("*a")

        outFile:write(string.format(result, Version.Major * 10000 + Version.Minor * 100 + Version.Patch, version, version))
        outFile:close()
    end

    inFile:close()
end