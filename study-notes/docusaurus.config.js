// @ts-check
import { themes as prismThemes } from 'prism-react-renderer';

/** @type {import('@docusaurus/types').Config} */
const config = {
    title: 'IT Study Notes', 
    tagline: 'Seneca CPAC Journey', 
    favicon: 'img/favicon.ico',

    url: 'https://jisunpark28.github.io',
    baseUrl: '/',

    organizationName: 'jisunpark28',
    projectName: 'my-course-portfolio',

    onBrokenLinks: 'throw',
    onBrokenMarkdownLinks: 'warn',

    i18n: {
        defaultLocale: 'en',
        locales: ['en'],
    },

    presets: [
        [
            'classic',
            /** @type {import('@docusaurus/preset-classic').Options} */
            ({
                docs: {
                    sidebarPath: './sidebars.js',
                    editUrl:
                        'https://github.com/jisunpark28/my-course-portfolio/tree/main/study-notes/',
                },
                blog: {
                    showReadingTime: true,
                    editUrl:
                        'https://github.com/jisunpark28/my-course-portfolio/tree/main/study-notes/',
                },
                theme: {
                    customCss: './src/css/custom.css',
                },
            }),
        ],
    ],

    themeConfig:
        /** @type {import('@docusaurus/preset-classic').ThemeConfig} */
        ({
            image: 'img/docusaurus-social-card.jpg',
            colorMode: {
                respectPrefersColorScheme: true,
            },
            navbar: {
                title: 'IT Study Notes', 
                logo: {
                    alt: 'My Site Logo',
                    src: 'img/logo.svg',
                },
                items: [
                    {
                        type: 'docSidebar',
                        sidebarId: 'tutorialSidebar',
                        position: 'left',
                        label: 'Study Notes', 
                    },
                    { to: '/blog', label: 'Blog', position: 'left' },
                    {
                        href: 'https://github.com/jisunpark28/my-course-portfolio',
                        label: 'GitHub',
                        position: 'right',
                    },
                ],
            },
            footer: {
                style: 'dark',
                links: [
                    {
                        title: 'Docs',
                        items: [
                            {
                                label: 'Study Notes',
                                to: '/docs/intro',
                            },
                        ],
                    },
                    {
                        title: 'Links',
                        items: [
                            {
                                label: 'LinkedIn',
                                href: 'https://www.linkedin.com/in/jisun-park-08a584254/', 
                            },
                        ],
                    },
                    {
                        title: 'More',
                        items: [
                            {
                                label: 'GitHub Repository',
                                href: 'https://github.com/jisunpark28/my-course-portfolio',
                            },
                        ],
                    },
                ],
                copyright: `Copyright © ${new Date().getFullYear()} Jisun Park. Built with Docusaurus.`,
            },
            prism: {
                theme: prismThemes.github,
                darkTheme: prismThemes.dracula,
                // C++ 코드를 많이 쓰시므로 추가하면 좋습니다
                additionalLanguages: ['cpp', 'csharp', 'bash', 'sql'],
            },
        }),
};

export default config;