param(
    [switch]$SkipInstall
)

$ErrorActionPreference = "Stop"

$root = (Resolve-Path (Join-Path $PSScriptRoot "..")).Path
$profileRoot = Join-Path $root ".acm-vscode"
$userDataDir = Join-Path $profileRoot "user-data"
$extensionsDir = Join-Path $profileRoot "extensions"
$userDir = Join-Path $userDataDir "User"
$snippetsDir = Join-Path $userDir "snippets"

New-Item -ItemType Directory -Force -Path $userDir, $snippetsDir, $extensionsDir | Out-Null

$settings = [ordered]@{
    "files.autoSave" = "afterDelay"
    "editor.mouseWheelZoom" = $true
    "editor.tabSize" = 4
    "editor.insertSpaces" = $true
    "editor.minimap.enabled" = $true
    "workbench.startupEditor" = "none"
    "workbench.sideBar.location" = "right"
    "update.showReleaseNotes" = $false
    "explorer.confirmDelete" = $false
    "explorer.confirmDragAndDrop" = $false
    "git.confirmSync" = $false
    "background.enabled" = $true
    "background.editor" = @{
        "images" = @("file:///D:/img1.wallspic.com-arzach-man_hua_shu-cha_hua_jia-sheng_tai_qu-zi_ran_huan_jing-2568x1440.png")
        "style" = @{
            "background-position" = "center"
            "background-repeat" = "no-repeat"
            "background-size" = "cover"
            "opacity" = 0.2
        }
    }
    "github.copilot.enable" = @{
        "*" = $false
        "plaintext" = $false
        "markdown" = $false
        "scminput" = $false
    }
}

$settings | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath (Join-Path $userDir "settings.json") -Encoding UTF8

$sourceSnippets = Join-Path $env:APPDATA "Code\User\snippets\cpp.json"
if (Test-Path -LiteralPath $sourceSnippets) {
    Copy-Item -LiteralPath $sourceSnippets -Destination (Join-Path $snippetsDir "cpp.json") -Force
}

$sourceKeybindings = Join-Path $env:APPDATA "Code\User\keybindings.json"
if (Test-Path -LiteralPath $sourceKeybindings) {
    Copy-Item -LiteralPath $sourceKeybindings -Destination (Join-Path $userDir "keybindings.json") -Force
}

$extensions = @(
    "divyanshuagrawal.competitive-programming-helper",
    "ms-vscode.cpptools",
    "usernamehw.errorlens",
    "adpyke.codesnap",
    "shalldie.background",
    "ms-ceintl.vscode-language-pack-zh-hans"
)

function Patch-CphAutoFolder {
    $cphDir = Get-ChildItem -LiteralPath $extensionsDir -Directory -Filter "divyanshuagrawal.competitive-programming-helper-*" -ErrorAction SilentlyContinue |
        Sort-Object LastWriteTime -Descending |
        Select-Object -First 1

    if (!$cphDir) {
        Write-Host "CPH extension is not installed yet; skip auto-folder patch."
        return
    }

    $jsPath = Join-Path $cphDir.FullName "dist\extension.js"
    if (!(Test-Path -LiteralPath $jsPath)) {
        Write-Host "CPH extension.js not found; skip auto-folder patch."
        return
    }

    $backupPath = Join-Path $cphDir.FullName "dist\extension.js.codex-bak"
    if (!(Test-Path -LiteralPath $backupPath)) {
        Copy-Item -LiteralPath $jsPath -Destination $backupPath
    }

    $text = [System.IO.File]::ReadAllText($jsPath, [System.Text.Encoding]::UTF8)

    $oldName = 'if((0,g.isCodeforcesUrl)(new URL(e.url))&&(0,p.useShortCodeForcesName)())return`${(0,v.getProblemName)(e.url)}.${t}`;if((0,g.isLuoguUrl)'
    $newName = 'if((0,g.isCodeforcesUrl)(new URL(e.url))&&(0,p.useShortCodeForcesName)())return`${(0,v.getProblemName)(e.url)}.${t}`;if((0,g.isCodeforcesUrl)(new URL(e.url)))return`${e.name.replace(/[<>:"\/\\|?*]+/g,"_")}.${t}`;if((0,g.isLuoguUrl)'
    if ($text.Contains($oldName)) {
        $text = $text.Replace($oldName, $newName)
    } elseif (!$text.Contains($newName)) {
        Write-Warning "Could not find CPH filename patch point."
    }

    $oldPath = 'const u=(0,t.getProblemFileName)(e,o),v=f.default.join(r,u);if(e.srcPath=v,e.tests=e.tests.map'
    $newPath = 'const u=(0,t.getProblemFileName)(e,o);let v=f.default.join(r,u);if((0,g.isCodeforcesUrl)(a)){const m=a.pathname.match(/\/(?:contest|gym)\/(\d+)\/problem\/([A-Za-z0-9]+)/)||a.pathname.match(/\/problemset\/problem\/(\d+)\/([A-Za-z0-9]+)/),b=m?f.default.join(r,"CodeForces",m[1]):f.default.join(r,"CodeForces");(0,d.existsSync)(b)||(0,d.mkdirSync)(b,{recursive:!0}),v=f.default.join(b,u)}if(e.srcPath=v,e.tests=e.tests.map'
    if ($text.Contains($oldPath)) {
        $text = $text.Replace($oldPath, $newPath)
    } elseif (!$text.Contains($newPath)) {
        Write-Warning "Could not find CPH path patch point."
    }

    [System.IO.File]::WriteAllText($jsPath, $text, [System.Text.Encoding]::UTF8)
    Write-Host "Patched CPH Codeforces auto-folder behavior."
}

if (!$SkipInstall) {
    foreach ($extension in $extensions) {
        Write-Host "Installing $extension"
        code --extensions-dir $extensionsDir --install-extension $extension
        if ($LASTEXITCODE -ne 0) {
            throw "Failed to install $extension"
        }
    }
}

Patch-CphAutoFolder

Write-Host "ACM profile user data: $userDataDir"
Write-Host "ACM profile extensions: $extensionsDir"
