import glob

tags = {
    '## Example:\n': '## EXAMPLE\n',
    '## Example 1:\n': '## EXAMPLE 1\n',
    '## Example 2:\n': '## EXAMPLE 2\n',
    '## Example 3:\n': '## EXAMPLE 3\n',
    '## EXAMPLE:\n': '## EXAMPLE\n',
    '## EXAMPLE 1:\n': '## EXAMPLE 1\n',
    '## EXAMPLE 2:\n': '## EXAMPLE 2\n',
    '## EXAMPLE 3:\n': '## EXAMPLE 3\n',
    '## Note:\n': '## NOTE\n',
    '## NOTE:\n': '## NOTE\n',
} # oldname newname


def main():
    worklist = glob.glob("*/*/*.md")
    tot = 0
    for filename in worklist:
        text = []
        with open(filename, 'r', encoding='utf-8') as fin:
            text = fin.readlines()
        hit = 0
        for i in range(len(text)):
            if text[i][:3] != "## ":
                continue
            for k, v in tags.items():
                if text[i].find(k) < 0:
                    continue
                text[i] = text[i].replace(k, v)
                hit += 1
        if hit == 0:
            continue
        tot += 1
        with open(filename, 'w', encoding='utf-8') as fout:
            fout.writelines(text)
        print(f'{filename} done, replace {hit} point(s)')
    print(f'Update {tot} file(s). Job done.')


if __name__ == "__main__":
    main()
