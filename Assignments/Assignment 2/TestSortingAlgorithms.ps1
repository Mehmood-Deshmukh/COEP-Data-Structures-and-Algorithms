if (-Not (Test-Path -Path "results")) {
    New-Item -ItemType Directory -Path "results"
}

$sortingAlgorithms = @(
    @{ Name = "mergeSort"; Path = ".\Sorting Algorithms\mergeSort.exe" },
    @{ Name = "selectionSort"; Path = ".\Sorting Algorithms\selectionSort.exe" }
)

$testCases = @(
    ".\Test Cases\1k.txt",
    ".\Test Cases\5k.txt",
    ".\Test Cases\10k.txt",
    ".\Test Cases\50k.txt",
    ".\Test Cases\100k.txt",
    ".\Test Cases\500k.txt",
    ".\Test Cases\1m.txt"
)

foreach ($algorithm in $sortingAlgorithms) {
    $algoResultsPath = "results\$($algorithm.Name)"
    if (-Not (Test-Path -Path $algoResultsPath)) {
        New-Item -ItemType Directory -Path $algoResultsPath
    }

    foreach ($testCase in $testCases) {
        $testCaseName = [System.IO.Path]::GetFileNameWithoutExtension($testCase)

        $timeTaken = Measure-Command {
            Get-Content $testCase | & $algorithm.Path
        }

        $resultFilePath = "$algoResultsPath\$testCaseName.txt"
        $timeTaken | Out-File -FilePath $resultFilePath
    }
}
